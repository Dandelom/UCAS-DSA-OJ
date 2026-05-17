#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode
{
  int data;
  struct PolyNode *next;
} PolyNode, *PolyLink;

typedef PolyLink LinkedPoly;

typedef struct Monomial
{
    int coefficient; //系数
    int degree; //次数
} Term;

Term getterm(char firstDigit); //取数

int main()
{
    LinkedPoly list;
    list=(LinkedPoly)malloc(sizeof(PolyNode));
    list->data=0;
    list->next=list;
    char c;
    int sign=1, maxDegree=0;
    while((c=getchar()) && c != EOF)
    {
        if(c == '-') sign=-1;
        else if(c == '+') sign=1;
        else if(c >= '0' && c <= '9')
        {
            Term curTerm=getterm(c);
            if(curTerm.degree > maxDegree) maxDegree=curTerm.degree;
            curTerm.coefficient*=sign;
            PolyNode *pin=list;
            for(int i=0; i<curTerm.degree; i++)
            {
                if(pin->next == list)
                {
                    PolyNode *p=malloc(sizeof(PolyNode));
                    p->data=0;
                    p->next=list;
                    pin->next=p;
                    pin=p;
                }
                else pin=pin->next;
            }
            pin->data+=curTerm.coefficient;
        }
    }
    // 反转链表
    PolyNode *pcur, *plast, *pnext;
    plast=list;
    pcur=plast->next;
    pnext=pcur->next;
    while(pnext!=list)
    {
        pcur->next=plast;
        plast=pcur;
        pcur=pnext;
        pnext=pnext->next;
    }
    pcur->next=plast;
    pnext->next=pcur;
    // 输出
    PolyNode *pin=list->next;
    int curDegree=maxDegree;
    int zeroFlag=0;
    while(curDegree > 0)
    {
        if(pin->data != 0)
        {
            zeroFlag=1;
            if(pin->data < 0)
            {
                if(curDegree == maxDegree) printf("- ");
                else printf(" - ");
                pin->data*=-1;
            }
            else
            {
                if(curDegree != maxDegree) printf(" + ");
            }
            printf("%d", pin->data*curDegree);
            if(curDegree == 2) printf("x");
            else if(curDegree > 2) printf("x^%d", curDegree-1);
        }
        curDegree--;
        pin=pin->next;
    }
    if(zeroFlag == 0) printf("0");
    return 0;
}

Term getterm(char firstDigit)
{
    Term curTerm;
    curTerm.coefficient=firstDigit-'0';
    curTerm.degree=0;
    char c;
    while((c=getchar()) && (c >= '0' && c <= '9'))
    {
        curTerm.coefficient*=10;
        curTerm.coefficient+=c-'0';
    }
    if(c == ' ') return curTerm;
    else if(c == 'x')
    {
        c=getchar();
        if(c == '^')
        {
            while((c=getchar()) && (c >= '0' && c <= '9'))
            {
                curTerm.degree*=10;
                curTerm.degree+=c-'0';
            }
        }
        else curTerm.degree=1;
        return curTerm;
    }
    return curTerm;
}