#define LEFT 050
#define RIGHT 051
int longestValidParentheses(char* s)
{
    int cnt = 0, level = 0;
    char *old = s;
    char *begin = s, *end = s;
    for (; *s != '\0'; s++)
    {
        switch (*s)
        {
        case LEFT:
            ++level;
            break;
        case RIGHT:
            --level;
            break;
        }
        if (level < 0)
        {
            cnt = end - begin > cnt ? end - begin : cnt;
            end = begin = s + 1;
            level = 0;
        }
        else if(level == 0)
            end = s + 1;
    }
    cnt = end - begin > cnt ? end - begin : cnt;
    if (level > 0)
    {
        level = 0;
        --old;
        end = begin = s;
        for (--s; s != old; --s)
        {
            switch (*s)
            {
            case LEFT:
                --level;
                break;
            case RIGHT:
                ++level;
                break;
            }
            if (level < 0)
            {
                cnt = end - begin > cnt ? end - begin : cnt;
                end = begin = s;
                level = 0;
            }
            else if(level == 0)
                begin = s;
        }
        cnt = end - begin > cnt ? end - begin : cnt;
    }
    return cnt;
}
