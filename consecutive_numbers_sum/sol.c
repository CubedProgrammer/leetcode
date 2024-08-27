int consecutiveNumbersSum(int n)
{
    int mini = 1, tot = 0;
    for (int i = 1; mini <= n; mini += i)
    {
        tot += n % i == mini % i;
        ++i;
    }
    return tot;
}
