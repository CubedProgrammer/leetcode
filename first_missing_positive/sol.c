int firstMissingPositive(int* nums, int numsSize)
{
    int to;
    for(int i = 0; i < numsSize; ++i)
    {
        while(nums[i] != i + 1 && nums[i] > 0 && nums[i] <= numsSize)
        {
            to = nums[i] - 1;
            if(nums[to] == nums[i])
                nums[to] = -1;
            nums[to] ^= nums[i] ^= nums[to] ^= nums[i];
        }
        if(nums[i] != i + 1)
            nums[i] = -1;
    }
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == -1)
            return i + 1;
    }
    return numsSize + 1;
}
