#include <stdio.h>

char stack[1000];
int top=0;

void push(char c);
void pop();

int main()
{
    char c;
    while((c=getchar()) && c != EOF)
    {
        if(c == '(') push(c);
        else if(c == ')')
        {
            if(top == 0 || stack[top-1] != '(')
            {
                printf("0");
                return 0;
            }
            pop();
        }
    }
    if(top == 0) printf("1");
    else printf("0");
    return 0;
}

void push(char c)
{
    stack[top++]=c;
}

void pop()
{
    stack[top--]='\0';
}