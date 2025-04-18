#include <stdbool.h>
#include <stdio.h>
bool isMatch(char* s, char* p);
int main(int argl, char *argv[])
{
    char str[121], pattern[121];
    scanf("%s %s", str, pattern);
    printf("%d\n", isMatch(str + (str[0] == '0'), pattern));
    return 0;
}
