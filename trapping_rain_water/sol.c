#define MAXN 20000
int trap(int* height, int heightSize)
{
    int prev[MAXN], next[MAXN];
    int stack[MAXN];
    int maxi, currheight;
    int nxtgreat = 0;
    unsigned stacklen = 0;
    unsigned tot = 0;
    for(int i = 0; i < heightSize; ++i)
    {
        for(; stacklen > 0 && height[stack[stacklen - 1]] < height[i]; --stacklen);
        prev[i] = stacklen == 0 ? -1 : stack[stacklen - 1];
        stack[stacklen++] = i;
    }
    stacklen = 0;
    for(int i = heightSize - 1; i >= 0; --i)
    {
        for(; stacklen > 0 && height[stack[stacklen - 1]] < height[i]; --stacklen);
        next[i] = stacklen == 0 ? heightSize : stack[stacklen - 1];
        stack[stacklen++] = i;
    }
    for(int i = 0; nxtgreat < heightSize; ++i)
    {
        if(i == nxtgreat)
        {
            nxtgreat = next[i];
            currheight = height[i];
            if(nxtgreat == heightSize)
                maxi = currheight;
        }
        else
            tot += currheight - height[i];
    }
    --nxtgreat;
    currheight = 0;
    for(int i = heightSize - 1; maxi > currheight; --i)
    {
        if(i == nxtgreat)
        {
            nxtgreat = prev[i];
            currheight = height[i];
        }
        else
            tot += currheight - height[i];
    }
    return tot;
}
