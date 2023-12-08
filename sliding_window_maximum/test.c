#include<stdio.h>
#include<stdlib.h>
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize);
int main(int argl, char *argv[])
{
    unsigned n, k;
    int *res, retSize;
    int arr[100];
    scanf("%u %u", &n, &k);
    for(unsigned i = 0; i < n; ++i)
        scanf("%i", arr + i);
    res = maxSlidingWindow(arr, n, k, &retSize);
    printf("%i", retSize);
    for(int i = 0; i < retSize; ++i)
        printf(" %i", res[i]);
    free(res);
    putchar('\n');
    return 0;
}
