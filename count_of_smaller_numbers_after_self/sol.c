int bit[20003];

void bit_update(int pos, int diff)
{
    for (; pos < 20003; pos += pos & -pos)
        bit[pos] += diff;
}

int bit_query(int pos)
{
    int tot = 0;
    for (; pos; pos -= pos & -pos)
        tot += bit[pos];
    return tot;
}

int* countSmaller(int* nums, int numsSize, int* returnSize)
{
    int tmp;
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
        bit_update(nums[i] += 10001, 1);
    for (int i = 0; i < numsSize; i++)
    {
        tmp = nums[i];
        nums[i] = bit_query(nums[i] - 1);
        bit_update(tmp, -1);
    }
    return nums;
}
