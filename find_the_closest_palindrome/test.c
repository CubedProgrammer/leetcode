#include <stdio.h>
#include <stdlib.h>
char* nearestPalindromic(char* n);
int main(int argl, char *argv[])
{
    char cbuf[121];
    char *res;
    scanf("%s", cbuf);
    printf("%s\n", res = nearestPalindromic(cbuf));
    free(res);
    return 0;
}
