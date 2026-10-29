#include <stdio.h>
#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);
int main(int argl, char *argv[])
{
    unsigned m, n;
    int *arr;
    scanf("%u %u", &m, &n);
    arr = malloc((m + n) * sizeof(*arr));
    for(unsigned i = 0; i < m + n; ++i)
        scanf("%d", arr + i);
    printf("%f\n", findMedianSortedArrays(arr, m, arr + m, n));
    free(arr);
    return 0;
}
