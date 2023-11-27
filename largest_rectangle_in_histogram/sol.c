#define MAXN 100000
unsigned left[MAXN], right[MAXN];
int stack[MAXN];
int largestRectangleArea(int* heights, int heightsSize)
{
    unsigned stacklen = 0;
    int maxi = 0, area;
    for(int i = 0; i < heightsSize; ++i)
    {
        while(stacklen > 0 && heights[stack[stacklen - 1]] >= heights[i])
            --stacklen;
        left[i] = stacklen == 0 ? -1 : stack[stacklen - 1];
        stack[stacklen++] = i;
    }
    stacklen = 0;
    for(int i = heightsSize - 1; i >= 0; --i)
    {
        while(stacklen > 0 && heights[stack[stacklen - 1]] >= heights[i])
            --stacklen;
        right[i] = stacklen == 0 ? heightsSize : stack[stacklen - 1];
        stack[stacklen++] = i;
    }
    for(int i = 0; i < heightsSize; ++i)
    {
        area = heights[i] * (right[i] - left[i] - 1);
        maxi = maxi < area ? area : maxi;
    }
    return maxi;
}
