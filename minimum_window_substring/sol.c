#include<stdlib.h>
#include<string.h>
char atLeast(const unsigned *sfreq, const unsigned *tfreq)
{
    for(int i = 0; i < 58; ++i)
    {
        if(sfreq[i] < tfreq[i])
            return 0;
    }
    return 1;
}
char* minWindow(char* s, char* t)
{
    unsigned sfreq[58], tfreq[58];
    unsigned slen = strlen(s), tlen = strlen(t);
    unsigned *lenarr = malloc(slen * sizeof(*lenarr));
    unsigned start = 0;
    unsigned mini = 99999999, ind;
    char move, *str;
    memset(sfreq, 0, sizeof sfreq);
    memset(tfreq, 0, sizeof tfreq);
    memset(lenarr, 0, sizeof(*lenarr) * slen);
    for(unsigned i = 0; i < tlen; ++i)
    {
        t[i] -= 'A';
        ++tfreq[t[i]];
    }
    for(; start < slen && tfreq[s[start] - 'A'] == 0; ++start);
    for(unsigned i = start; i < slen; ++i)
    {
        move = 0;
        s[i] -= 'A';
        ++sfreq[s[i]];
        if(sfreq[s[i]] > tfreq[s[i]])
            move = s[start] == s[i];
        if(atLeast(sfreq, tfreq))
        {
            lenarr[start] = i - start + 1;
            move = lenarr[start] > tlen;
            if(!move)
                break;
        }
        if(move)
        {
            --sfreq[s[start]];
            for(++start; sfreq[s[start]] > tfreq[s[start]]; ++start)
                --sfreq[s[start]];
        }
    }
    for(unsigned i = 0; i < slen; ++i)
    {
        if(lenarr[i] && lenarr[i] < mini)
        {
            ind = i;
            mini = lenarr[i];
        }
    }
    free(lenarr);
    if(mini == 99999999)
        mini = 0;
    str = malloc(mini + 1);
    for(unsigned i = 0; i < mini; ++i)
        str[i] = s[i + ind] + 'A';
    str[mini] = '\0';
    return str;
}
