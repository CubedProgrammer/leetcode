#include <stdbool.h>
#include <stdio.h>
bool isNumber(char* s);
int main(int argl, char *argv[])
{
    char cbuf[121];
    scanf("%s", cbuf);
    printf("%d\n", isNumber(cbuf));
    return 0;
}
