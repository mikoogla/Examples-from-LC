#include <stdio.h>


int removeElement(int* nums, int numsSize, int val){
    int p = 0;
    for(int i=0; i<numsSize; i++){
        if(nums[i] != val) {
            nums[p] = nums[i];
            p++;
        }
    }
    return p;
}

int main(){
    int array[] = {3, 2, 2, 3};
    removeElement(array, sizeof(array) / sizeof(int), 3);
    puts("debug");
    return 0;
}