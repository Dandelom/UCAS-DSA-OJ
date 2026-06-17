#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    char schoolName;
    int maleScore;
    int femaleScore;
} DATA;
DATA ans[5];

int main()
{
    char c[100];
    while(fgets(c, 100, stdin)!=NULL)
    {
        int i=0;
        while(c[i]!=' ') i++;
        i++;
        int score=atoi(c+i+4);
        ans[(c[i+2]-'A')].schoolName=c[i+2];
        if(c[i]=='M') ans[(c[i+2]-'A')].maleScore+=score;
        if(c[i]=='F') ans[(c[i+2]-'A')].femaleScore+=score;
    }
    for(int i=0; i<5; i++)
    {
        if(ans[i].schoolName==0) continue;
        if(ans[i].maleScore!=0) printf("%c M %d\n", ans[i].schoolName, ans[i].maleScore);
        if(ans[i].femaleScore!=0) printf("%c F %d\n", ans[i].schoolName, ans[i].femaleScore);
        printf("%c %d\n", ans[i].schoolName, ans[i].maleScore+ans[i].femaleScore);
    }
    return 0;
}