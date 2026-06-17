#include <stdio.h>
#include <stdlib.h>

void RadixSort(int arr[], int n);

int main()
{
    int arr[100005];
    int n=0;
    int val;
    while(scanf("%d", &val) == 1)
    {
        arr[n++]=val;
    }
    RadixSort(arr, n);
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

void RadixSort(int arr[], int n)
{
    if(n <= 0) return;
    int maxval=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i] > maxval) maxval=arr[i];
    }
    int *output=(int *)malloc(sizeof(int)*n);
    for(int exp=1; maxval/exp > 0; exp*=10)
    {
        int count[10]={0};
        for(int i=0; i<n; i++)
        {
            count[(arr[i]/exp)%10]++;
        }
        for(int i=1; i<10; i++)
        {
            count[i]+=count[i-1];
        }
        for(int i=n-1; i>=0; i--)
        {
            output[count[(arr[i]/exp)%10]-1]=arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for(int i=0; i<n; i++)
        {
            arr[i]=output[i];
        }
    }
    free(output);
}