#include<stdio.h>
int largestRectangleArea(int* heights, int heightsSize);
int main(int argl, char *argv[])
{
    int n, arr[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    printf("%d\n", largestRectangleArea(arr, n));
    return 0;
}
