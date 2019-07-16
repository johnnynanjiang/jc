//
// Created by Nan Jiang on 2019-07-15.
//

#include "gtest/gtest.h"

#include <string>

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

ListNode *make_list(vector<int> &vector) {
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

void make_tree_recursive(TreeNode *&rootNodePtr, int value) {
    if (rootNodePtr == nullptr) {
        rootNodePtr = new TreeNode{value};
        return;
    }

    if (rootNodePtr->val == value) {
        return;
    } else if (rootNodePtr->val > value) {
        return make_tree_recursive(rootNodePtr->left, value);
    } else {
        return make_tree_recursive(rootNodePtr->right, value);
    }
}

TreeNode *make_tree(vector<int> &vector) {
    TreeNode *rootNodePtr = nullptr;

    for (auto v : vector) {
        make_tree_recursive(rootNodePtr, v);
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
// TreeNode <<<

TEST(ListNode, make_list) {
    vector<int> vector = {0, 1, 2, 3};
    const ListNode *rootNodePtr = make_list(vector);

    ASSERT_EQ("0, 1, 2, 3, ", to_string(rootNodePtr));
}

TEST(treeNode, make_tree) {
    vector<int> vector = {0, 1, 2, 3};
    const TreeNode *rootNodePtr = make_tree(vector);

    ASSERT_EQ("0, NULL, 1, NULL, 2, NULL, 3, NULL, NULL, ", to_string(rootNodePtr));
}

TEST(search, binary_search_tree) {

}