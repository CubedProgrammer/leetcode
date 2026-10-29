#define BIG 32800
int cache[BIG][31];
unsigned queue[BIG*30][2];
int process(unsigned n, unsigned c)
{
    int pos = 0, speed = 1;
    for(; c; --c)
    {
        if(n >> (c-1) & 1)
        {
            pos += speed;
            speed *= 2;
        }
        else
            speed = speed < 0 ? 1 : -1;
    }
    return pos;
}
int racecar(int target)
{
    if(cache[target][30] > 0)
        return cache[target][30];
    unsigned qbegin = 0, qend = 1;
    unsigned pos, speed;
    unsigned revind, nxtpos;
    queue[0][0] = 0;
    queue[0][1] = 0;
    while(qbegin != qend)
    {
        pos = queue[qbegin][0];
        speed = queue[qbegin][1];
        nxtpos = (unsigned)1 << (speed >> 1);
        nxtpos = (speed & 1) == 1 ? pos - nxtpos : pos + nxtpos;
        revind = (speed & 1) == 1 ? 0 : 1;
        if((pos != 0 || revind != 0) && cache[pos][revind] == 0)
        {
            cache[pos][revind] = cache[pos][speed] + 1;
            queue[qend][0] = pos;
            queue[qend][1] = revind;
            ++qend;
        }
        if(nxtpos < BIG && speed < 28 && cache[nxtpos][speed + 2] == 0)
        {
            cache[nxtpos][speed + 2] = cache[pos][speed] + 1;
            queue[qend][0] = nxtpos;
            queue[qend][1] = speed + 2;
            ++qend;
        }
        ++qbegin;
    }
    for(unsigned i = 0; i < BIG; ++i)
    {
        int mini = 99999999;
        for(unsigned j = 0; j < 30; ++j)
        {
            if(cache[i][j] > 0)
                mini = cache[i][j] < mini ? cache[i][j] : mini;
        }
        cache[i][30] = mini;
    }
    return cache[target][30];
}
