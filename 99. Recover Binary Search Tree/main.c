#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main() {

    struct TreeNode *tree = newNode(3);
    tree->left = newNode(1);
    tree->right = newNode(4);
    tree->right->left = newNode(2);
    return 0;
}