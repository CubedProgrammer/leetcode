#include<stdio.h>
int numDistinct(char* s, char* t);
int main(int argl, char *argv[])
{
    char s[1001], t[1001];
    scanf("%s %s", s, t);
    printf("%d\n", numDistinct(s, t));
    return 0;
}
