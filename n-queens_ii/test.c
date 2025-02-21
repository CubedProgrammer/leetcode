#include<stdio.h>
int totalNQueens(int n);
int main(int argl, char *argv[])
{
    int n;
    scanf("%d", &n);
    printf("%d\n", totalNQueens(n));
    return 0;
}
