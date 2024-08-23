unsigned maxu(unsigned m, unsigned n)
{
    return m < n ? n : m;
}
unsigned bigRect(char* arr, unsigned len)
{
    unsigned stack[200];
    unsigned nextSmall[200], prevSmall[200];
    unsigned stacklen = 0;
    unsigned area, maxi = 0;
    for (unsigned i = 0; i < len; i++)
    {
        while (stacklen && (char unsigned)arr[stack[stacklen - 1]] >= (char unsigned)arr[i])
            --stacklen;
        if (stacklen == 0)
            prevSmall[i] = -1;
        else
            prevSmall[i] = stack[stacklen - 1];
        stack[stacklen++] = i;
    }
    stacklen = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        while (stacklen && (char unsigned)arr[stack[stacklen - 1]] >= (char unsigned)arr[i])
            --stacklen;
        if (stacklen == 0)
            nextSmall[i] = len;
        else
            nextSmall[i] = stack[stacklen - 1];
        stack[stacklen++] = i;
    }
    for (unsigned i = 0; i < len; i++)
    {
        area = (unsigned)(arr[i] & 0xff) * (nextSmall[i] - prevSmall[i] - 1);
        maxi = maxu(maxi, area);
    }
    return maxi;
}
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize)
{
    unsigned m = matrixSize, n = *matrixColSize;
    unsigned largest = 0;
    for (unsigned i = 0; i < m; i++)
    {
        for (unsigned j = 0; j < n; j++)
            matrix[i][j] -= '0';
    }
    for (unsigned i = 1; i < m; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            if (matrix[i][j])
                matrix[i][j] += matrix[i-1][j];
        }
    }
    for (unsigned i = 0; i < m; i++)
        largest = maxu(largest, bigRect(matrix[i], n));
    return largest;
}
