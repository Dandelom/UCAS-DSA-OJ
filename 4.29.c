#include <stdio.h>

void getNextval(char pat[], int nextval[], int len);
int KMP(char str[], char pat[], int nextval[], int len1, int len2);

int main()
{
    int len1, len2;
    scanf("%d%d", &len1, &len2);
    char str[len1+1], pat[len2+1];
    int i=0;
    while(i<len1)
    {
        char c=getchar();
        if(c != '\n') str[i++]=c;
    }
    str[i]='\0';
    i=0;
    while(i<len2)
    {
        char c=getchar();
        if(c != '\n') pat[i++]=c;
    }
    pat[i]='\0';
    // puts(str);
    // puts(pat);
    int nextval[len1];
    getNextval(pat, nextval, len2);
    printf("%d", KMP(str, pat, nextval, len1, len2));
    return 0;
}

void getNextval(char pat[], int nextval[], int len)
{
    int j=0, k=-1;
    nextval[0]=-1;
    while(j < len)
    {
        if(k == -1 || pat[j] == pat[k])
        {
            j++;
            k++;
            if(pat[j] == pat[k]) nextval[j]=nextval[k];
            else nextval[j]=k;
        }
        else k=nextval[k];
    }
    return;
}

int KMP(char str[], char pat[], int nextval[], int len1, int len2)
{
    int j=0, k=0;
    while(j < len1)
    {
        if(k == -1 || str[j] == pat[k])
        {
            j++;
            k++;
        }
        else k=nextval[k];
        if(k == len2) return j-len2;
    }
    return -1;
}