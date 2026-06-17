#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10005];
    int c[10005];
    int n=0;
    int val;
    while(scanf("%d", &val) == 1)
    {
        a[n++]=val;
    }
    for(int i=0; i<n; i++)
    {
        int count=0;
        for(int j=0; j<n; j++)
        {
            if(a[j] < a[i])
            {
                count++;
            }
        }
        c[i]=count;
    }
    int dotflag=0;
    for(int i=0; i<n; i++)
    {
        if(dotflag) putchar(' ');
        printf("%d", c[i]);
        if(!dotflag) dotflag=1;
    }
    printf("\n");
    return 0;
}