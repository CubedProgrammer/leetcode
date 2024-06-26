int candy(int* ratings, int ratingsSize)
{
    int tot = 0;
    int valley, peak;
    char descending = 0, isvalley = 0;
    int first = 0, last = ratingsSize - 1;
    int cnt = 2, ocnt;
    if (ratingsSize == 1)
        return 1;
    for (; first + 1 < ratingsSize && ratings[first] > ratings[first + 1]; first++);
    for (; last > 0 && ratings[last] >= ratings[last - 1]; --last);
    valley = first;
    for(int j = first - 1; j > 0; --j)
    {
        ocnt = cnt;
        if (ratings[j] < ratings[j - 1])
            ++cnt;
        else
            cnt = 1;
        ratings[j] = ocnt;
    }
    if (first != 0)
        ratings[0] = cnt;
    for (int i = first + 1; i <= last; i++)
    {
        if (i != last)
        {
            isvalley = descending && ratings[i] <= ratings[i + 1];
            descending = ratings[i] > ratings[i + 1];
        }
        else
            isvalley = 1;
        if (isvalley)
        {
            cnt = 1;
            for (; ratings[valley] <= ratings[valley + 1]; valley++)
            {
                ocnt = cnt;
                if (ratings[valley] < ratings[valley + 1])
                    ++cnt;
                else
                    cnt = 1;
                ratings[valley] = ocnt;
            }
            peak = cnt;
            cnt = 2;
            for(int j = i - 1; j > valley; --j)
            {
                ocnt = cnt;
                if (ratings[j] < ratings[j - 1])
                    ++cnt;
                else
                    cnt = 1;
                ratings[j] = ocnt;
            }
            if (cnt > peak)
                ratings[valley] = cnt;
            else
                ratings[valley] = peak;
            valley = i;
        }
    }
    cnt = 1;
    for (; last < ratingsSize - 1; last++)
    {
        ocnt = cnt;
        if (ratings[last] < ratings[last + 1])
            ++cnt;
        else
            cnt = 1;
        ratings[last] = ocnt;
    }
    ratings[last] = cnt;
    for (int i = 0; i < ratingsSize; i++)
        tot += ratings[i];
    return tot;
}
