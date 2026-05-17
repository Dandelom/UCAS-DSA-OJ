#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char c[n];
    for(int i=0; i<n; i++)
        c[i]=getchar();
    for(int i=0; i<n/2; i++)
    {
        if(c[i] != c[n-i-1])
        {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}