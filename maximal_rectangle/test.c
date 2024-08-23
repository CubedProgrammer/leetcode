#include<stdio.h>
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize);
int main(int argl, char *argv[])
{
    unsigned m, n;
    char *ptrs[30];
    char mat[961];
    scanf("%u %u", &m, &n);
    getchar();
    fread(mat, 1, m * (n + 1), stdin);
    for (unsigned i = 0; i < m; i++)
    {
        mat[i * (n + 1) + n] = '\0';
        ptrs[i] = mat + i * (n + 1);
    }
    printf("%d\n", maximalRectangle(ptrs, m, &n));
    return 0;
}
