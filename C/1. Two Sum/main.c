int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ans = malloc(sizeof(int) * 2);
    *returnSize = 2;

    for(int i = 0; i<numsSize; i++){
        for(int j = 0; j<numsSize; j++){
            if(i == j) continue;
            else{
                if(*(nums + i) + *(nums + j) == target){
                    *(ans + 0) = i;
                    *(ans + 1) = j;
                }
            }
        }
    }
    return ans;
}