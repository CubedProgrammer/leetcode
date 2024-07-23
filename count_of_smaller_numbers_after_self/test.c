#include<stdio.h>
int* countSmaller(int* nums, int numsSize, int* returnSize);
int main(int argl, char *argv[])
{
    int n;
    int arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    countSmaller(arr, n, &n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("");
    return 0;
}
