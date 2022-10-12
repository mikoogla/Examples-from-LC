#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *returnElement(struct ListNode *e, int n) {
    if(e == NULL) return NULL;
    struct ListNode *node = e;
    for (int i = 0; i < n; i++) {
        if (node->next != NULL)
            node = node->next;
        else
            return NULL;
    }
    return node;
}

struct ListNode *returnLast(struct ListNode *e) {
    struct ListNode *node = e;
    if (node->next == node) {
        return node;
    }
    while (1) {
        if (node->next == NULL) {
            return node;
        } else {
            node = node->next;
        }
    }
}

void push(struct ListNode *outcome, struct ListNode *n1, struct ListNode *n2, int *bit) {
    int val1 = 0, val2 = 0;
    if(n1 != NULL) val1 = n1->val;
    if(n2 != NULL) val2 = n2->val;
    struct ListNode *node = malloc(sizeof(struct ListNode));

    node->next = NULL;

    if (val1 + val2 + *bit >= 10) {
        node->val = val1 + val2 + *bit - 10;
        *bit = 1;
    } else {
        node->val = val1 + val2 + *bit;
        *bit = 0;
    }
    if (outcome->next == NULL && outcome->val == -1) {
        outcome->val = node->val;
    } else
        returnLast(outcome)->next = node;
}

void printlist(struct ListNode *outcome) {
    struct ListNode *out = outcome;
    printf("[");
    while (1) {
        if (out->next == NULL) {
            printf("%d]", out->val);
            return;
        } else {
            printf("%d", out->val);
            out = out->next;
        }
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *outcome = malloc(sizeof(struct ListNode));
    outcome->next = NULL;
    outcome->val = -1;

    int bit = 0;

    for (int i = 0; !(returnElement(l1, i) == NULL && returnElement(l2, i) == NULL); i++){
        push(outcome, returnElement(l1, i), returnElement(l2, i), &bit);
    }
    if(bit == 1){
        push(outcome, 0, 0, &bit);
    }
    return outcome;
}

int main() {
    struct ListNode nums1[] = {
            {
                    .val = 5,
                    .next = NULL
            },
            {
                    .val = 6,
                    .next = NULL
            }
    };
    nums1[0].next = &nums1[1];

    struct ListNode nums2[] = {
            {
                    .val = 5,
                    .next = NULL
            },
            {
                    .val = 4,
                    .next = NULL
            },
            {
                    .val = 9,
                    .next = NULL
            }
    };
    nums2[0].next = &nums2[1];
    nums2[1].next = &nums2[2];
    nums2[2].next = NULL;

    puts("wynik: ");
    printlist(addTwoNumbers(nums1, nums2));
    return 0;
}
