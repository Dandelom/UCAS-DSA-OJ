#include <stdio.h>
#include <stdlib.h>

int main()
{
    int status=0; // 0:normal 1:ignore 2:string
    char c;
    while((c=getchar()) && c != EOF)
    {
        if(status == 0)
        {
            if(c == '/')
            {
                c=getchar();
                if(c == '*') status=1;
                else printf("/%c", c);
            }
            else if(c == '"')
            {
                putchar(c);
                status=2;
            }
            else putchar(c);
        }
        else if(status == 1)
        {
            if(c == '*')
            {
                c=getchar();
                if(c == '/') status=0;
            }
        }
        else if(status == 2)
        {
            if(c == '"')
            {
                status=0;
                putchar(c);
            }
            else if(c == '\\')
            {
                putchar(c);
                c=getchar();
                putchar(c);
            }
            else putchar(c);
        }
    }
    return 0;
}