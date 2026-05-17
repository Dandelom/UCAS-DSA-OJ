#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int F[n+1];
    F[0]=1;
    for(int i=1; i<=n; i++)
    {
        F[i]=i*F[i/2];
    }
    printf("%d", F[n]);
    return 0;
}