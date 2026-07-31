/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int FirInd = 0; FirInd < numsSize; FirInd++) {
        int a = nums[FirInd];
        for (int SecInd = FirInd + 1; SecInd < numsSize; SecInd++) {
            if (a + nums[SecInd] == target) {
                int* res = malloc(2 * sizeof(int));
                res[0] = FirInd;
                res[1] = SecInd;
                *returnSize = 2;
                return res;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int returnSize = 0;
    int* res = twoSum(nums, 4, 9, &returnSize);
    printf("index: [%d, %d]\n", res[0], res[1]);
    return 0;
}

