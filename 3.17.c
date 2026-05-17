#include <stdio.h>

char array[1000];

int main()
{
    char c;
    int len=0, ans=1;
    while((c=getchar()) && c != '&')
        array[len++]=c;
    while((c=getchar()) && c != '@')
    {
        if(c != array[--len])
        {
            ans=0;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}