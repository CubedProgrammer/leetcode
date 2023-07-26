#include<stdio.h>
int firstMissingPositive(int* nums, int numsSize);
int main(int argl, char *argv[])
{
    int n;
    int arr[30];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    printf("%d\n", firstMissingPositive(arr, n));
    return 0;
}
