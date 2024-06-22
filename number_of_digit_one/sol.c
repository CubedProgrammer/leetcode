int countDigitOne(int n)
{
    int dig;
    long toadd = 1;
    long perdig = 0;
    int tot = 0;
    int og = n;
    while(n > 0)
    {
        dig = n % 10;
        tot += perdig * dig;
        if(dig > 1)
            tot += toadd;
        else if(dig == 1)
            tot += og % toadd + 1;
        perdig *= 10;
        perdig += toadd;
        toadd *= 10;
        n /= 10;
    }
    return tot;
}
