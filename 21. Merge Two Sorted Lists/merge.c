#include "merge.h"
#define INIT 101

void push(struct ListNode *output, struct ListNode *value) {

    if (output->val == INIT) {
        output->val = value->val;
        return;
    }
    struct ListNode *node = malloc(sizeof(struct ListNode));
    while (output->next != NULL) {
        output = output->next;
    }
    output->next = node;
    node->val = value->val;
    node->next = NULL;
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    if (list1 == NULL && list2 == NULL) return NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode *outcome = malloc(sizeof(struct ListNode));
    outcome->val = INIT;
    outcome->next = NULL;
    struct ListNode *p = list1, *q = list2;
    //first iteration
    if (!(p == NULL && q == NULL)) {
        if (p != NULL && q != NULL) {
            if (p->val < q->val) {
                push(outcome, p);
                p = p->next;
            } else {
                push(outcome, q);
                q = q->next;
            }
        }
        if (p == NULL && q != NULL) {
            push(outcome, q);
            q = q->next;
        }
        if (q == NULL && p != NULL) {
            push(outcome, p);
            p = p->next;
        }
    } else return NULL;

    while (p != NULL || q != NULL) {
        if (p != NULL && q != NULL) {
            if (p->val < q->val) {
                push(outcome, p);
                p = p->next;
            } else {
                push(outcome, q);
                q = q->next;
            }
        }
        if (p == NULL && q != NULL) {
            push(outcome, q);
            q = q->next;
        }
        if (q == NULL && p != NULL) {
            push(outcome, p);
            p = p->next;
        }
    }
    return outcome;
}