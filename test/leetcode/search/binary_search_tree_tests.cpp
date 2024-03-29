//
// Created by Nan Jiang on 2019-07-15.
//

#include "gtest/gtest.h"

#include <string>
#include <list>
#include <queue>
#include <cmath>

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

uint32_t height(TreeNode *&rootNodePtr) {
    if (rootNodePtr == nullptr) return 0;
    return 1 + std::max(height(rootNodePtr->left),
                        height(rootNodePtr->right));
}

int height_balance(TreeNode *&rootNodePtr) {
    if (rootNodePtr == nullptr) return 0;
    return height(rootNodePtr->left) -
           height(rootNodePtr->right);
}

uint32_t max_capacity(uint32_t height) {
    return std::pow(2, height) - 1;
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

std::string to_string(std::vector<const TreeNode *> nodeList) {
    std::string output{};

    for (auto node : nodeList) {
        output += (node == nullptr ? "*" : std::to_string(node->val)) + ",";
    }

    return output;
}

std::string to_string(const std::vector<std::vector<string>> &matrix) {
    std::string output{};

    for (auto row : matrix) {
        std::string colString{};

        for (auto col : row) {
            colString += (col + ", ");
        }

        output += colString + '\n';
    }

    return output;
}

std::vector<const TreeNode *> to_list(TreeNode *rootNodePtr) {
    uint32_t treeHeight = height(rootNodePtr);
    uint32_t maxCapacity = max_capacity(treeHeight - 1);
    vector<const TreeNode *> nodeList;

    nodeList.push_back(rootNodePtr);
    uint32_t i = 0;

    while (i < maxCapacity) {
        const TreeNode *treeNode = nodeList[i];

        if (nodeList[i] == nullptr) {
            nodeList.push_back(nullptr);
            nodeList.push_back(nullptr);
        } else {
            nodeList.push_back(treeNode->left);
            nodeList.push_back(treeNode->right);
        }

        ++i;
    }

    return nodeList;
}

uint32_t width(uint32_t height) {
    uint32_t i = 0;
    uint32_t width = 0;

    while (i < height) {
        width += std::pow(2, i);
        ++i;
    }

    return width;
}

std::vector<std::vector<string>> draw_tree(TreeNode *&rootNodePtr) {
    uint32_t matrixHeight = height(rootNodePtr);
    uint32_t matrixWidth = width(matrixHeight);
    std::vector<const TreeNode *> nodeList = to_list(rootNodePtr);
    std::vector<std::vector<string>> matrix(matrixHeight, std::vector<string>(matrixWidth, " "));

    uint32_t currentIndexInNodeList = 0;
    for (uint32_t i = 0; i < matrixHeight; ++i) {
        uint32_t numberOfNodes = std::pow(2, i);
        uint32_t currentPositionInMatrix = matrixWidth / (2 * numberOfNodes);
        uint32_t interval = (matrixWidth / (2 * std::pow(2, i - 1))) + 1;

        for (uint32_t j = 0; j < numberOfNodes; ++j) {
            matrix[i][currentPositionInMatrix] = (nodeList[currentIndexInNodeList] == nullptr ?
                                                  " " : std::to_string(nodeList[currentIndexInNodeList]->val));
            ++currentIndexInNodeList;
            currentPositionInMatrix += interval;
        }
    }

    return matrix;
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

TEST(TreeNode, tree_height) {
    TreeNode *rootNodePtr = make_tree(fixture_vector);

    ASSERT_EQ(4, height(rootNodePtr));
    ASSERT_EQ(3, height(rootNodePtr->right));
    ASSERT_EQ(2, height(rootNodePtr->right->right));
    ASSERT_EQ(1, height(rootNodePtr->right->right->right));
    ASSERT_EQ(0, height(rootNodePtr->right->right->right->right));
}

TEST(TreeNode, tree_height_balance) {
    TreeNode *rootNodePtr = make_tree(fixture_vector);

    ASSERT_EQ(-3, height_balance(rootNodePtr));
    ASSERT_EQ(-2, height_balance(rootNodePtr->right));
    ASSERT_EQ(-1, height_balance(rootNodePtr->right->right));
    ASSERT_EQ(0, height_balance(rootNodePtr->right->right->right));
}

TEST(TreeNode, tree_height_balance_reverse) {
    TreeNode *rootNodePtr = make_tree(fixture_vector_reverse);

    ASSERT_EQ(3, height_balance(rootNodePtr));
    ASSERT_EQ(2, height_balance(rootNodePtr->left));
    ASSERT_EQ(1, height_balance(rootNodePtr->left->left));
    ASSERT_EQ(0, height_balance(rootNodePtr->left->left->left));
}

TEST(TreeNode, tree_to_queue) {
    TreeNode *rootNodePtr = make_tree(fixture_vector);

    vector<const TreeNode *> nodeList = to_list(rootNodePtr);

    ASSERT_EQ("0,*,1,*,*,*,2,*,*,*,*,*,*,*,3,", to_string(nodeList));
}

TEST(TreeNode, matrix_width) {
    ASSERT_EQ(1, width(1));
    ASSERT_EQ(3, width(2));
    ASSERT_EQ(7, width(3));
    ASSERT_EQ(15, width(4));
}

TEST(TreeNode, draw_full_tree) {
    const vector<int> full_tree_vector = {10, 5, 50, 1, 6, 30, 60};
    TreeNode *rootNodePtr = make_tree(full_tree_vector);

    vector<const TreeNode *> nodeList = to_list(rootNodePtr);

    ASSERT_EQ("10,5,50,1,6,30,60,", to_string(nodeList));

    auto matrix = draw_tree(rootNodePtr);

    cout << to_string(matrix) << endl;
}

TEST(TreeNode, draw_ugly_tree) {
    TreeNode *rootNodePtr = make_tree(fixture_vector);

    vector<const TreeNode *> nodeList = to_list(rootNodePtr);

    ASSERT_EQ("0,*,1,*,*,*,2,*,*,*,*,*,*,*,3,", to_string(nodeList));

    auto matrix = draw_tree(rootNodePtr);

    cout << to_string(matrix) << endl;
}

TEST(TreeNode, draw_simple_tree) {
    TreeNode *rootNodePtr = make_tree({1, 2});

    vector<const TreeNode *> nodeList = to_list(rootNodePtr);

    ASSERT_EQ("1,*,2,", to_string(nodeList));

    auto matrix = draw_tree(rootNodePtr);

    cout << to_string(matrix) << endl;
}