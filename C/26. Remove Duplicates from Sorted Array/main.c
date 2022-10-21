#include <stdio.h>
//int removeDuplicates(int*nums,int numsSize){int j=1;for(int i=1;i<numsSize;i++){if(nums[i]!=nums[i-1]){nums[j]=nums[i];j++;}}return j;}
int removeDuplicates(int *nums, int numsSize) {
    int j = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main() {
    int nums[] = {1, 1, 2, 3, 3, 3, 3, 5, 7, 8};
    removeDuplicates(nums, sizeof(nums) / sizeof(int));
    puts("gotowe");
    return 0;
}