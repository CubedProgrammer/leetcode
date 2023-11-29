#include<stdio.h>
int trap(int* height, int heightSize);
int main(int argl, char *argv[])
{
    int n, arr[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    printf("%d\n", trap(arr, n));
    return 0;
}
