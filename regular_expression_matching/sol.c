#include <stdbool.h>
#include <string.h>
bool isMatch(char* s, char* p)
{
    char matches[21][21];
    unsigned slen = strlen(s);
    unsigned plen = strlen(p);
    memset(matches, 0, sizeof(matches));
    matches[0][0] = 1;
    for(unsigned i = 1; i <= plen; ++i)
    {
        if(p[i-1] == '*')
            matches[0][i] = matches[0][i-2];
    }
    for(unsigned i = 1; i <= slen; ++i)
    {
        for(unsigned j = 1; j <= plen; ++j)
        {
            switch(p[j-1])
            {
            case'*':
                matches[i][j] = matches[i][j-2];
                if(!matches[i][j])
                {
                    if(p[j-2] == '.')
                    {
                        for(unsigned k = 0; k < i; ++k)
                            matches[i][j] = matches[i][j] || matches[k][j];
                    }
                    else
                    {
                        for(unsigned k = i; k > 0 && s[k-1] == p[j-2]; --k)
                            matches[i][j] = matches[i][j] || matches[k-1][j];
                    }
                }
                break;
            case'.':
                matches[i][j] = matches[i-1][j-1];
                break;
            default:
                matches[i][j] = matches[i-1][j-1] && s[i-1] == p[j-1];
            }
        }
    }
    return matches[slen][plen];
}
