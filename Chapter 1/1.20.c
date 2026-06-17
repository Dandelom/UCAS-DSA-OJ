#include <stdio.h>

int main()
{
    int x, n, ans=0, temp=1;
    scanf("%d%d", &x, &n);
    for(int i=0; i<=n; i++)
    {
        int a;
        scanf("%d", &a);
        ans+=a*temp;
        temp*=x;
    }
    printf("%d", ans);
    return 0;
}