#include <stdio.h>

#define INTMAX 2147483647

typedef struct
{
    int x;
    int y;
    int value;
}Elem;

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int matrixA[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &matrixA[i][j]);
    int minValueInRow[m];
    for(int i=0; i<m; i++)
    {
        minValueInRow[i]=INTMAX;
        for(int j=0; j<n; j++)
        {
            if(matrixA[i][j] < minValueInRow[i])
                minValueInRow[i]=matrixA[i][j];
        }
    }
    int maxValueInColumn[n];
    for(int j=0; j<n; j++)
    {
        maxValueInColumn[j]=-INTMAX;
        for(int i=0; i<m; i++)
        {
            if(matrixA[i][j] > maxValueInColumn[j])
                maxValueInColumn[j]=matrixA[i][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrixA[i][j] == minValueInRow[i] && matrixA[i][j] == maxValueInColumn[j])
                printf("%d ", matrixA[i][j]);
        }
    }
    return 0;
}

// 最坏情况下的时间复杂度：O(m*n)