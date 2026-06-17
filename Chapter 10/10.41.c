#include <stdio.h>
#include <stdlib.h>

int arr[10001];

int main()
{
    for(int i=0; i<1000; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr[temp]++;
    }
    for(int i=1; i<=10000; i++)
    {
        for(int j=0; j<arr[i]; j++)
        {
            printf("%d ", i);
        }
    }
    return 0;
}