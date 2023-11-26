#include<stdio.h>
#include<stdlib.h>
char* minWindow(char* s, char* t);
int main(int argl, char *argv[])
{
    char s[100], t[100];
    scanf("%s %s", s, t);
    char *u = minWindow(s, t);
    puts(u);
    free(u);
    return 0;
}
