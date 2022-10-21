#ifndef LEETCODE_MERGE_H
#define LEETCODE_MERGE_H
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
#endif //LEETCODE_MERGE_H
