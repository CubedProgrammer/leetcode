#include<stdlib.h>
#include<string.h>
int max(int x, int y)
{
    return x > y ? x : y;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int table[16][100000];
    int range;
    unsigned r = 0;
    int *res = malloc((*returnSize = numsSize - k + 1) * sizeof(*res));
    if(k == 1)
        memcpy(res, nums, numsSize * sizeof(int));
    else
    {
        for(int i = 0; i < numsSize - 1; ++i)
            table[r][i] = max(nums[i], nums[i + 1]);
        for(range = 2; range << 1 < k; range <<= 1)
        {
            for(int i = 0; i < numsSize - (range << 1) + 1; ++i)
                table[r + 1][i] = max(table[r][i], table[r][i + range]);
            ++r;
        }
        for(int i = 0; i < *returnSize; ++i)
            res[i] = max(table[r][i], table[r][i + k - range]);
    }
    return res;
}
