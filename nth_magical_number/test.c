#include<stdio.h>
int nthMagicalNumber(int n, int a, int b);
int main(int argl, char *argv[])
{
    int n;
    int a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", nthMagicalNumber(n, a, b));
    return 0;
}
