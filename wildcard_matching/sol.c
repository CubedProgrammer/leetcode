#include <stdbool.h>
#include <string.h>
#define QMARK '?'
#define ASTER '*'
char results[2000][2000];
char hasMatch[2000];
bool isMatch(char* s, char* p)
{
    size_t slen = strlen(s), plen = strlen(p);
    unsigned required = 0;
    if (plen == 0)
        return slen == 0;
    if (slen == 0)
    {
        for (char const *it = p; *it != '\0'; ++it)
        {
            if (*it != ASTER)
                return false;
        }
        return true;
    }
    memset(hasMatch, 0, plen);
    results[0][0] = s[0] == p[0] || p[0] == QMARK || p[0] == ASTER;
    required = p[0] != ASTER;
    hasMatch[0] = results[0][0] || !required;
    required += !results[0][0];
    for (char const *it = p + 1; *it != '\0'; ++it)
    {
        required += *it != ASTER;
        if (*it != QMARK && *it != ASTER && *it != s[0])
            ++required;
        results[it - p][0] = required <= 1;
        hasMatch[it - p] = hasMatch[it - p] || results[it - p][0];
    }
    for (size_t j = 1; j < slen; j++)
    {
        results[0][j] = p[0] == ASTER;
        for (size_t i = 1; i < plen; i++)
        {
            switch (p[i])
            {
            case QMARK:
                results[i][j] = results[i-1][j-1];
                break;
            case ASTER:
                results[i][j] = hasMatch[i-1];
                break;
            default:
                results[i][j] = results[i-1][j-1] * (s[j] == p[i]);
                break;
            }
            hasMatch[i] = hasMatch[i] || results[i][j];
        }
    }
    return results[plen - 1][slen - 1];
}
