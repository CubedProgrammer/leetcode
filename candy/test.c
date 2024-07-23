#include<stdio.h>
int candy(int* ratings, int ratingsSize);
int main(int argl, char *argv[])
{
    int n, ans;
    int arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    ans = candy(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("%d\n", ans);
    return 0;
}
