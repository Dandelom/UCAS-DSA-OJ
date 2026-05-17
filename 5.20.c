#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int coeff[m][m];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &coeff[i][j]);
    int firstFlag=0;
    for(int i=m-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(coeff[i][j] == 0) continue;
            if(firstFlag == 0) firstFlag=1;
            else putchar('+');
            if(coeff[i][j] != 1) printf("%d", coeff[i][j]);
            if(i > 0) printf("xE%d", i);
            if(j > 0) printf("yE%d", j);
        }
    }
    return 0;
}