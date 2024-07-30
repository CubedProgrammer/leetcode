int copy[200][200];
int max(int x, int y)
{
    return x < y ? y : x;
}
void duplicate(int **dungeon, int m, int n)
{
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            copy[i][j] = dungeon[i][j];
    }
}
int survives(int m, int n, int hp)
{
    copy[0][0] += hp;
    if (copy[0][0] <= 0)
        return 0;
    for(int i = 1; i < n; ++i)
    {
        copy[0][i] += copy[0][i - 1];
        if (copy[0][i] <= 0)
            copy[0][i] = -99999999;
    }
    for(int i = 1; i < m; ++i)
    {
        copy[i][0] += copy[i - 1][0];
        if (copy[i][0] <= 0)
            copy[i][0] = -99999999;
    }
    for(int i = 1; i < m; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            copy[i][j] += max(copy[i - 1][j], copy[i][j - 1]);
            if (copy[i][j] <= 0)
                copy[i][j] = -99999999;
        }
    }
    return copy[m - 1][n - 1] > 0;
}
int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize)
{
    int m = dungeonSize, n = *dungeonColSize;
    int lo = 1, hi = 399000;
    int mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        duplicate(dungeon, m, n);
        if (survives(m, n, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}
