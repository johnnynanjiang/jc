//
// Created by Nan Jiang on 2019-07-15.
//

#include "gtest/gtest.h"

#include <string>
#include <list>

using namespace std;

/**
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 *
 */

// ListNode >>>
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *make_list(const vector<int> &vector) {
    ListNode *rootNodePtr = nullptr;
    ListNode *lastNodePtr = nullptr;

    for (auto v : vector) {
        ListNode *newNodePtr = new ListNode(v);

        if (rootNodePtr == nullptr) {
            rootNodePtr = newNodePtr;
        } else {
            lastNodePtr->next = newNodePtr;
        }

        lastNodePtr = newNodePtr;
    }

    return rootNodePtr;
}

std::string to_string(const ListNode *&rootNodePtr) {
    ListNode *nodePtr = const_cast<ListNode *>(rootNodePtr);
    std::string output{};

    while (nodePtr != nullptr) {
        output += std::to_string(nodePtr->val) + ", ";
        nodePtr = nodePtr->next;
    }

    return output;
}
// ListNode <<<

// TreeNode >>>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode *&rootNodePtr, int value) {
    if (rootNodePtr == nullptr) {
        rootNodePtr = new TreeNode{value};
        return;
    }

    if (rootNodePtr->val == value) {
        return;
    } else if (rootNodePtr->val > value) {
        return insert(rootNodePtr->left, value);
    } else {
        return insert(rootNodePtr->right, value);
    }
}

int height(const TreeNode *&rootNodePtr) {
    if (rootNodePtr == nullptr) return 0;
    return 1 + std::max(height(const_cast<const TreeNode *&>(rootNodePtr->left)),
                        height(const_cast<const TreeNode *&>(rootNodePtr->right)));
}

int height_balance(const TreeNode *&rootNodePtr) {
    if (rootNodePtr == nullptr) return 0;
    return height(const_cast<const TreeNode *&>(rootNodePtr->left)) -
           height(const_cast<const TreeNode *&>(rootNodePtr->right));
}

void balance_tree(TreeNode *&rootNodePtr) {

}

TreeNode *make_tree(const vector<int> &vector) {
    TreeNode *rootNodePtr = nullptr;

    for (auto v : vector) {
        insert(rootNodePtr, v);
    }

    return rootNodePtr;
}

std::string to_string(const TreeNode *&rootNodePtr) {
    std::string output{};

    if (rootNodePtr == nullptr) return "NULL, ";

    output += std::to_string(rootNodePtr->val) + ", ";
    output += to_string(const_cast<const TreeNode *&>(rootNodePtr->left));
    output += to_string(const_cast<const TreeNode *&>(rootNodePtr->right));

    return output;
}

void draw_tree(const TreeNode *&rootNodePtr) {
    struct node_depth {
        const TreeNode *n;
        int lvl;

        node_depth(const TreeNode *n_, int lvl_) : n(n_), lvl(lvl_) {}
    };

    int depth = height(rootNodePtr);

    char buf[1024];
    int last_lvl = 0;
    int offset = (1 << depth) - 1;

    // using a queue means we perform a breadth first iteration through the tree
    std::list<node_depth> q;

    q.push_back(node_depth(rootNodePtr, last_lvl));
    while (q.size()) {
        const node_depth &nd = *q.begin();

        // moving to a new level in the tree, output a new line and calculate new offset
        if (last_lvl != nd.lvl) {
            std::cout << "\n";

            last_lvl = nd.lvl;
            offset = (1 << (depth - nd.lvl)) - 1;
        }

        // output <offset><data><offset>
        if (nd.n)
            sprintf(buf, " %*s%d%*s", offset, " ", nd.n->val, offset, " ");
        else
            sprintf(buf, " %*s%s%*s", offset, " ", "nil", offset, " ");
        std::cout << buf;

        if (nd.n) {
            q.push_back(node_depth(nd.n->left, last_lvl + 1));
            q.push_back(node_depth(nd.n->right, last_lvl + 1));
        }

        q.pop_front();
    }
    std::cout << "\n";
}
// TreeNode <<<

const vector<int> fixture_vector = {0, 1, 2, 3};
const vector<int> fixture_vector_reverse = {3, 2, 1, 0};

TEST(ListNode, make_list) {

    const ListNode *rootNodePtr = make_list(fixture_vector);

    ASSERT_EQ("0, 1, 2, 3, ", to_string(rootNodePtr));
}

TEST(TreeNode, make_tree) {
    const TreeNode *rootNodePtr = make_tree(fixture_vector);

    ASSERT_EQ("0, NULL, 1, NULL, 2, NULL, 3, NULL, NULL, ", to_string(rootNodePtr));
}

TEST(TreeNode, height) {
    const TreeNode *rootNodePtr = make_tree(fixture_vector);

    ASSERT_EQ(4, height(rootNodePtr));
    ASSERT_EQ(3, height(const_cast<const TreeNode *&>(rootNodePtr->right)));
    ASSERT_EQ(2, height(const_cast<const TreeNode *&>(rootNodePtr->right->right)));
    ASSERT_EQ(1, height(const_cast<const TreeNode *&>(rootNodePtr->right->right->right)));
    ASSERT_EQ(0, height(const_cast<const TreeNode *&>(rootNodePtr->right->right->right->right)));
}

TEST(TreeNode, height_balance) {
    const TreeNode *rootNodePtr = make_tree(fixture_vector);

    ASSERT_EQ(-3, height_balance(rootNodePtr));
    ASSERT_EQ(-2, height_balance(const_cast<const TreeNode *&>(rootNodePtr->right)));
    ASSERT_EQ(-1, height_balance(const_cast<const TreeNode *&>(rootNodePtr->right->right)));
    ASSERT_EQ(0, height_balance(const_cast<const TreeNode *&>(rootNodePtr->right->right->right)));
}

TEST(TreeNode, height_balance_reverse) {
    const TreeNode *rootNodePtr = make_tree(fixture_vector_reverse);

    ASSERT_EQ(3, height_balance(rootNodePtr));
    ASSERT_EQ(2, height_balance(const_cast<const TreeNode *&>(rootNodePtr->left)));
    ASSERT_EQ(1, height_balance(const_cast<const TreeNode *&>(rootNodePtr->left->left)));
    ASSERT_EQ(0, height_balance(const_cast<const TreeNode *&>(rootNodePtr->left->left->left)));
}

TEST(TreeNode, draw_full_tree) {
    const vector<int> full_tree_vector = {10, 5, 50, 1, 6, 30, 60};
    const TreeNode *rootNodePtr = make_tree(full_tree_vector);

    draw_tree(rootNodePtr);
}

TEST(TreeNode, draw_ugly_tree) {
    const TreeNode *rootNodePtr = make_tree(fixture_vector);

    draw_tree(rootNodePtr);
}

TEST(search, binary_search_tree) {

}