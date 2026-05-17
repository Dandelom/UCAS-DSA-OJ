#include <stdio.h>

int fArray[1000000];

int main()
{
    int k, m;
    scanf("%d%d", &k, &m);
    int count=k-1, temp=0;
    if(m<k-1)
    {
        printf("0");
        return 0;
    }
    else if(m==k-1)
    {
        printf("1");
        return 0;
    }
    else
    {
        fArray[k-1]=1;
    }
    while(count!=m)
    {
        fArray[count+1]=fArray[count]+temp;
        temp=temp-fArray[count-k+1]+fArray[count];
        count++;
    }
    printf("%d", fArray[count]);
    return 0;
}