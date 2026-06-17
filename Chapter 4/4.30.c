#include <stdio.h>

int main()
{
    char s[10000];
    int len=0;
    char c;
    while((c=getchar()) && c != '\n' && c != EOF)
        s[len++]=c;
    s[len]='\0';
    int maxlen=-1, pos=0;
    int i=0;
    while(i < len)
    {
        int j=0, k=-1;
        int next[len+1];
        next[0]=-1;
        while(j < len)
        {
            if(k == -1 || s[i+j] == s[i+k])
            {
                j++;
                k++;
                next[j]=k;
            }
            else k=next[k];
        }
        while(j >= 0)
        {
            if(next[j] > maxlen)
            {
                maxlen=next[j];
                pos=i;
            }
            j--;
        }
        i++;
    }
    if(maxlen == 0)
    {
        printf("-1");
        return 0;
    }
    for(int i=0; i<maxlen; i++)
        putchar(s[pos+i]);
    putchar(' ');
    printf("%d", pos);
    return 0;
}