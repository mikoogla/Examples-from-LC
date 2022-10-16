#include "merge.h"

void printlist(struct ListNode *outcome) {
    struct ListNode *out = outcome;
    printf("[");
    while (1) {
        if (out->next == NULL) {
            printf("%d]\n", out->val);
            return;
        } else {
            printf("%d ", out->val);
            out = out->next;
        }
    }
}

int main() {
    struct ListNode nums1[] = {
            {
                    .val = 1,
                    .next = NULL
            }
    };

    struct ListNode nums2[] = {
            {
                    .val = 2,
                    .next = NULL
            }
    };

    printlist(nums1);
    printlist(nums2);
    printlist(mergeTwoLists(nums1, nums2));
    return 0;
}