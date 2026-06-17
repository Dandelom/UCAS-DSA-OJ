#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleCircularLinkedList
{
    int data;
    int freq;
    int rank; //记录访问次序
    struct DoubleCircularLinkedList *next;
    struct DoubleCircularLinkedList *prior;
} Node, *Linkedlist;

int main()
{
    int len;
    scanf("%d", &len);
    Linkedlist list;
    list=(Linkedlist)malloc(sizeof(Node));
    list->next=list;
    list->prior=list;
    list->freq=0;
    list->rank=0;
    Node *pin=list;
    for(int i=0; i<len; i++)
    {
        Node *p;
        p=(Node*)malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->freq=0;
        p->rank=0;
        p->prior=pin;
        p->next=list;
        pin->next=p;
        pin=p;
    }
    pin->next=list->next;
    list->next->prior=pin;
    list=pin->next; //处理尾结点和头节点之间的联系
    pin=list;
    int element;
    int counter=1;
    while(scanf("%d", &element))
    {
        pin=list;
        if(element==list->data)
        {
            list->freq++;
            if(list->rank==0)
            {
                list->rank=counter;
                counter++;
            }
        }
        else
        {
            pin=pin->next;
            while(pin!=list)
            {
                if(pin->data==element)
                {
                    pin->freq++;
                    if(pin->rank==0)
                    {
                        pin->rank=counter;
                        counter++;
                    }
                    Node *pfind;
                    pfind=list;
                    while(pfind->freq >= pin->freq)
                    {
                        if(pfind->freq == pin->freq && pfind->rank > pin->rank) break;
                        pfind=pfind->next;
                        if(pfind==pin) break;
                    }
                    if(pfind==pin) break;
                    //调整位置先删除，再插入
                    pin->prior->next=pin->next;
                    pin->next->prior=pin->prior; //删除
                    pfind->prior->next=pin;
                    pin->prior=pfind->prior;
                    pin->next=pfind;
                    pfind->prior=pin;
                    if(pin->freq > list->freq || (pin->freq == list->freq && pin->rank < list->rank)) list=pin;
                    break;
                }
                else pin=pin->next;
            }
        }
        char c=getchar();
        if(c=='\n') break;
    }
    pin=list;
    while(pin->next!=list)
    {
        printf("%d ", pin->data);
        pin=pin->next;
    }
    printf("%d", pin->data);
    return 0;
}