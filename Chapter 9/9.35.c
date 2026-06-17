#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[100000];
    if (!fgets(line, sizeof(line), stdin)) return 0;
    
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 0;
    
    int arr[20005];
    int n = 0;
    char *token = strtok(line, " \t\r\n");
    while (token != NULL)
    {
        arr[n++] = atoi(token);
        token = strtok(NULL, " \t\r\n");
    }
    
    int first = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > a && arr[i] < b)
        {
            if (!first) printf(" ");
            printf("%d", arr[i]);
            first = 0;
        }
    }
    printf("\n");
    
    return 0;
}