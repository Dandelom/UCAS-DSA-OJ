#include <stdio.h>
#include <stdlib.h>

void Heapify(int arr[], int n, int i)
{
    int largest=i;
    while(1)
    {
        int left=3*i+1;
        int mid=3*i+2;
        int right=3*i+3;
        if(left < n && arr[left] > arr[largest])
        {
            largest=left;
        }
        if(mid < n && arr[mid] > arr[largest])
        {
            largest=mid;
        }
        if(right < n && arr[right] > arr[largest])
        {
            largest=right;
        }
        if(largest != i)
        {
            int temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            i=largest;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int arr[], int n)
{
    if(n <= 1)
    {
        return;
    }
    for(int i=(n-2)/3; i>=0; i--)
    {
        Heapify(arr, n, i);
    }
    for(int i=n-1; i>0; i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        Heapify(arr, i, 0);
    }
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
    HeapSort(arr, n);
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

/*
时间复杂度分析：
1. 建堆阶段：时间复杂度为 O(n)。

2. 排序阶段：O(n log n)。

3. 综合总时间复杂度：O(n log n)。
*/