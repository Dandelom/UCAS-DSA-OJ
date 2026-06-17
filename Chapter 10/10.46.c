#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key;
} Record;

void QuickSortIdx(int idx[], Record b[], int low, int high)
{
    if (low >= high) return;
    int i = low, j = high;
    int pivot_idx = idx[low];
    int pivot_key = b[pivot_idx].key;
    while (i < j)
    {
        while (i < j && b[idx[j]].key >= pivot_key) j--;
        if (i < j) idx[i] = idx[j];
        while (i < j && b[idx[i]].key <= pivot_key) i++;
        if (i < j) idx[j] = idx[i];
    }
    idx[i] = pivot_idx;
    QuickSortIdx(idx, b, low, i - 1);
    QuickSortIdx(idx, b, i + 1, high);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    
    Record *b = (Record *)malloc(sizeof(Record) * n);
    Record *a = (Record *)malloc(sizeof(Record) * n);
    int *idx = (int *)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i].key);
        idx[i] = i;
    }
    
    QuickSortIdx(idx, b, 0, n - 1);
    
    for (int i = 0; i < n; i++)
    {
        a[i] = b[idx[i]];
    }
    
    int dotflag = 0;
    for (int i = 0; i < n; i++)
    {
        if (dotflag) putchar(' ');
        printf("%d", a[i].key);
        if (!dotflag) dotflag = 1;
    }
    printf("\n");
    
    free(b);
    free(a);
    free(idx);
    return 0;
}