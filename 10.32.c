#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[4]={0, 0, 0, 0};
    int temp;
    while(scanf("%d", &temp) == 1)
    {
        arr[temp]++;
    }
    for(int i=1; i<=3; i++)
    {
        for(int j=0; j<arr[i]; j++)
        {
            printf("%d ", i);
        }
    }
    return 0;
}