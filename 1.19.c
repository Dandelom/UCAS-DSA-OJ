#include <stdio.h>

int main()
{
    int n, arrsize;
    scanf("%d%d", &n, &arrsize);
    if(n>arrsize)
    {
        printf("-1\n");
        return 0;
    }
    if(n==0)
    {
        printf("1\n");
        return 0;
    }
    int a[n];
    a[0]=1;
    for(int i=1; i<n; i++)
    {
        a[i]=a[i-1]*2*i;
        if(a[i]<0)
        {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0; i<n-1; i++)
        printf("%d ", a[i]);
    printf("%d", a[n-1]);
    return 0;
}