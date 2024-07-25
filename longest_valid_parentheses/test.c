#include<stdio.h>
int longestValidParentheses(char* s);
int main(int argl, char *argv[])
{
    char cbuf[91];
    scanf("%s", cbuf);
    printf("%i\n", longestValidParentheses(cbuf));
    return 0;
}
