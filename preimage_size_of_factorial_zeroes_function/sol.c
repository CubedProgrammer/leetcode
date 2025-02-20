int preimageSizeFZF(int k)
{
    long moduli[15] = {6};
    long l = k;
    for(int i = 1; i < 15; ++i)
        moduli[i] = moduli[i-1] * 5 + 1;
    for(int i = 14; i >= 0; --i)
    {
        l %= moduli[i];
        if(l + 1 == moduli[i])
            return 0;
    }
    return 5;
}
