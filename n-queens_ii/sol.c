int isValid(const int *first, const int *last)
{
    const int v = last[-1];
    for(const int *iti = first; iti != last - 1; ++iti)
    {
        if(*iti == v || last - iti - 1 == v - *iti || last - iti - 1 == *iti - v)
            return 0;
    }
    return 1;
}
int totalNQueens(int n)
{
    int cnt = 0;
    int arr[9] = {0};
    int *pos = arr + 1;
    if(n == 1)
        return 1;
    for(;;)
    {
        for(; *pos != n && !isValid(arr, pos + 1); ++*pos);
        if(*pos == n)
        {
            *pos = 0;
            if(pos == arr)
                break;
            ++*--pos;
        }
        else if(pos == arr + n - 1)
        {
            ++cnt;
            ++*pos;
        }
        else
            ++pos;
    }
    return cnt;
}
