#include <stdio.h>

char prior[7][7]=
{
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'<', '<', '<', '<', '<', '=', 'X'},
    {'>', '>', '>', '>', 'X', '>', '>'},
    {'<', '<', '<', '<', '<', 'X', '='}
};

char pop();
void push(char c);
int getNum(char c);

char stack[1000];
int top=0;

int main()
{
    char c;
    push('#');
    while((c=getchar()) && c != EOF && c != '\n')
    {
        if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
        {
            putchar(c);
            continue;
        }
        else
        {
            int num1=getNum(stack[top-1]), num2=getNum(c);
            while(prior[num1][num2] == '>')
            {
                putchar(pop());
                num1=getNum(stack[top-1]);
            }
            if(prior[num1][num2] == '<') push(c);
            else if(prior[num1][num2] == '=') top--;
        }
    }
    while(top != 1) putchar(pop());
    return 0;
}

char pop()
{
    if(top == 0) return '0';
    char c=stack[--top];
    return c;
}

void push(char c)
{
    stack[top++]=c;
    return;
}

int getNum(char c)
{
    switch(c)
    {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        case '#':
            return 6;
        default:
            return -1; 
    }
    return -1;
}