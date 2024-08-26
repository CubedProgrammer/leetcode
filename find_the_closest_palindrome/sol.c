#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char isPalin(const char *first, const char *last)
{
    while (first != last)
    {
        --last;
        if (*first != *last)
            return 0;
        if (first != last)
            ++first;
    }
    return 1;
}
void makePalin(char *first, char *middle, char *last)
{
    for (; first != middle; ++first)
        *--last = *first;
}
void incdec(char *first, char *last, char signed direc)
{
    char check = direc > 0 ? '9' : '0';
    for (char *it = --last; it != first; --it)
    {
        if (*it != check)
        {
            *it += direc;
            break;
        }
    }
}
char* nearestPalindromic(char* n)
{
    char *last, *middle;
    char *res;
    char already;
    unsigned cnt, ncnt;
    long unsigned tmp;
    long unsigned num = 0, val;
    long unsigned left = 0, right = 0;
    for (last = n; *last != '\0'; ++last);
    cnt = last - n;
    res = malloc(cnt + 3);
    for (unsigned i = 0; i * 2 < cnt; i++)
        num = num * 10 + (n[i] - '0');
    val = num;
    already = isPalin(n, last);
    middle = n + cnt / 2;
    for (char const *it = middle + cnt % 2; it < last; it++)
        val = val * 10 + (*it - '0');
    if (already)
    {
        if (cnt == 1)
        {
            res[0] = n[0] - 1;
            res[1] = '\0';
        }
        else
        {
            ncnt = sprintf(res, "%lu", val + 2);
            if (isPalin(res, res + ncnt))
                return res;
            ncnt = sprintf(res, "%lu", val - 2);
            if (isPalin(res, res + ncnt))
                return res;
            ncnt = sprintf(res, "%lu", num + 1);
            ncnt -= cnt % 2;
            makePalin(res, res + ncnt, res + cnt);
            res[cnt] = '\0';
            right = strtoul(res, NULL, 10);
            ncnt = sprintf(res, "%lu", num - 1);
            ncnt -= cnt % 2;
            makePalin(res, res + ncnt, res + cnt);
            res[cnt] = '\0';
            left = strtoul(res, NULL, 10);
            if (val - left > right - val)
                sprintf(res, "%lu", right);
        }
    }
    else
    {
        makePalin(n, middle, last);
        tmp = strtoul(n, NULL, 10);
        if (tmp > val)
        {
            right = tmp;
            if (num == 1)
            {
                memcpy(res, "9", 2);
                return res;
            }
            ncnt = sprintf(res, "%lu", num - 1);
            ncnt -= cnt % 2;
            if (ncnt < cnt / 2)
            {
                sprintf(res, "%lu", val - 1);
                return res;
            }
            makePalin(res, res + ncnt, res + cnt);
            res[cnt] = '\0';
            left = strtoul(res, NULL, 10);
            if (val - left > right - val)
                memcpy(res, n, cnt + 1);
        }
        else
        {
            left = tmp;
            ncnt = sprintf(res, "%lu", num + 1);
            ncnt -= cnt % 2;
            makePalin(res, res + ncnt, res + cnt);
            res[cnt] = '\0';
            right = strtoul(res, NULL, 10);
            if (val - left <= right - val)
                memcpy(res, n, cnt + 1);
        }
    }
    return res;
}
