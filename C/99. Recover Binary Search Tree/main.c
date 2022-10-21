#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct OrderNodes {
    struct TreeNode *node;
    struct OrderNodes *next;
};
struct OrderNodes *array;

struct TreeNode *newNode(int val) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void initialiseArray() {
    array = malloc(sizeof(struct OrderNodes));
    array->node = NULL;
    array->next = NULL;
}

void addToArray(struct OrderNodes *OrderedNode) {
    if (OrderedNode == NULL || OrderedNode->node == NULL) return;
    struct OrderNodes *p = array;

    //add first element
    if (p->node == NULL) {
        p->node = OrderedNode->node;
        return;
    }

    //add another element
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = OrderedNode;
}

void search(struct TreeNode *root) {
    if (root == NULL) return;
    search(root->left);

    struct OrderNodes *orderedNode = malloc(sizeof(struct OrderNodes));
    orderedNode->node = root;
    orderedNode->next = NULL;
    addToArray(orderedNode);


    search(root->right);
}

void swap(struct TreeNode *n1, struct TreeNode *n2) {
    int temp = n1->val;
    n1->val = n2->val;
    n2->val = temp;
}

void recoverTree(struct TreeNode *root) {
    if (root == NULL) return;
    initialiseArray();
    struct OrderNodes *p = array;
    search(root);

    int sorted = 0;
    while (sorted == 0) {
        sorted = 1;
        while (p->next != NULL) {
            if (p->node->val > p->next->node->val) {
                sorted = 0;
                swap(p->node, p->next->node);
            }
            p = p->next;
        }
        p = array;
    }
}

int main() {
    struct TreeNode *tree = newNode(1);
    tree->left = newNode(3);
    tree->left->right = newNode(2);

    recoverTree(tree);
    return 0;
}