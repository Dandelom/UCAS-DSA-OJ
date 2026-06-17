#include <stdio.h>
#include <string.h>
#define MAXLEN 101

int main()
{
    char a[MAXLEN], b[MAXLEN];
    fgets(a, MAXLEN, stdin);
    fgets(b, MAXLEN, stdin);
    int flag=strcmp(a, b);
    if(flag>0) printf("2");
    else if(flag==0) printf("0");
    else printf("1");
    return 0;
}