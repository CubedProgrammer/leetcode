#include<stdio.h>
#include<stdlib.h>
int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize);
int main(int argl, char *argv[])
{
    int m, n;
    scanf("%d %d", &m, &n);
    int **d = malloc(m * sizeof(*d));
    for(int i = 0; i < m; ++i)
        d[i] = malloc(n * sizeof(*d[i]));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            scanf("%d", &d[i][j]);
    }
    printf("%d\n", calculateMinimumHP(d, m, &n));
    for(int i = 0; i < m; ++i)
        free(d[i]);
    free(d);
    return 0;
}
