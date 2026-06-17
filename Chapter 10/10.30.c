#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int low;
    int high;
}SubSeq;

void DirectSort(int arr[], int low, int high)
{
    for(int i=low; i<=high; i++)
    {
        for(int j=i+1; j<=high; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int Partition(int arr[], int low, int high)
{
    int pivot=arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= pivot)
        {
            high--;
        }
        arr[low]=arr[high];
        while(low < high && arr[low] <= pivot)
        {
            low++;
        }
        arr[high]=arr[low];
    }
    arr[low]=pivot;
    return low;
}

void QuickSort(int arr[], int n)
{
    if(n <= 1)
    {
        return;
    }
    SubSeq *stack=(SubSeq *)malloc(sizeof(SubSeq)*(n+5));
    int top=0;
    stack[top].low=0;
    stack[top].high=n-1;
    top++;
    while(top > 0)
    {
        top--;
        int low=stack[top].low;
        int high=stack[top].high;
        if(high - low + 1 <= 3)
        {
            DirectSort(arr, low, high);
            continue;
        }
        int pivot=Partition(arr, low, high);
        int len1=pivot - low;
        int len2=high - pivot;
        if(len1 > len2)
        {
            if(len1 > 0)
            {
                stack[top].low=low;
                stack[top].high=pivot-1;
                top++;
            }
            if(len2 > 0)
            {
                stack[top].low=pivot+1;
                stack[top].high=high;
                top++;
            }
        }
        else
        {
            if(len2 > 0)
            {
                stack[top].low=pivot+1;
                stack[top].high=high;
                top++;
            }
            if(len1 > 0)
            {
                stack[top].low=low;
                stack[top].high=pivot-1;
                top++;
            }
        }
    }
    free(stack);
}

int main()
{
    int arr[100005];
    int n=0;
    int val;
    while(scanf("%d", &val) == 1)
    {
        arr[n++]=val;
    }
    QuickSort(arr, n);
    int dotflag=0;
    for(int i=0; i<n; i++)
    {
        if(dotflag) putchar(' ');
        printf("%d", arr[i]);
        if(!dotflag) dotflag=1;
    }
    printf("\n");
    return 0;
}