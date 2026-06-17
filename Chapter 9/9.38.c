#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int arr[40005];
    int n = 0;
    char line1[100000];
    char line2[100000];

    if (fgets(line1, sizeof(line1), stdin))
    {
        char *token = strtok(line1, " \t\r\n");
        while (token != NULL)
        {
            int val = atoi(token);
            if (val != -1)
            {
                arr[n++] = val;
            }
            token = strtok(NULL, " \t\r\n");
        }
    }

    if (fgets(line2, sizeof(line2), stdin))
    {
        char *token = strtok(line2, " \t\r\n");
        while (token != NULL)
        {
            int val = atoi(token);
            if (val != -1)
            {
                arr[n++] = val;
            }
            token = strtok(NULL, " \t\r\n");
        }
    }

    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}