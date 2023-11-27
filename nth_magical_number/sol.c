int magical[90000];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int nthMagicalNumber(int n, int a, int b)
{
    if(b < a)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int lcm = a * b / gcd(b, a);
    int amult = a, bmult = b;
    long num = lcm;
    unsigned cnt = 1;
    for(; amult < lcm; ++cnt)
    {
        if(bmult < amult)
        {
            magical[cnt] = bmult;
            bmult += b;
        }
        else
        {
            magical[cnt] = amult;
            amult += a;
        }
    }
    num *= n / cnt;
    n %= cnt;
    return(num + magical[n]) % 1000000007;
}
