unsigned cache[1000][1000];
int numDistinct(char* s, char* t)
{
    unsigned slen = 1;
    unsigned i;
    cache[0][0] = s[0] == t[0];
    for(; s[slen] != '\0'; ++slen)
        cache[0][slen] = cache[0][slen-1] + (s[slen] == t[0]);
    for(i = 1; t[i] != '\0'; ++i)
    {
        cache[i][i-1] = 0;
        for(unsigned j = i; j < slen; ++j)
        {
            cache[i][j] = cache[i][j-1];
            if(s[j] == t[i])
            {
                cache[i][j] += cache[i-1][j-1];
            }
        }
    }
    return cache[i - 1][slen - 1];
}
