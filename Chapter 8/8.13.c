#include <stdio.h>
#include <stdlib.h>

typedef struct Space
{
    int tag;
    int iniaddr;
    int size;
    struct Space *next; 
}Space;

int main()
{
    int tag, iniaddr, size;
    Space *mem=NULL;
    while(scanf("%d%d%d", &tag, &iniaddr, &size) == 3)
    {
        Space *new=(Space *)malloc(sizeof(Space));
        new->tag=0;
        new->iniaddr=iniaddr;
        new->size=size;
        new->next=NULL;
        if(!mem) mem=new;
        else
        {
            Space *p=mem;
            int endaddr=iniaddr+size;
            while(p)
            {
                int p_endaddr = p->iniaddr + p->size;

                // ----- 重叠检查 -----
                if (iniaddr < p_endaddr && p->iniaddr < endaddr) { // 有重叠
                    // 忽略该释放块，不修改链表
                    free(new);
                    break;
                }

                // 当前节点是最后一个
                if (!p->next) {
                    if (p_endaddr == iniaddr) {                 // 邻接在后
                        p->size += size;
                        free(new);
                    } else if (endaddr == p->iniaddr) {         // 邻接在前
                        p->iniaddr = iniaddr;
                        p->size += size;
                        free(new);
                    } else if (endaddr < p->iniaddr) {          // 完全在前，插入 p 之前
                        Space *pp = mem;
                        if (pp == p) {
                            new->next = p;
                            mem = new;
                        } else {
                            while (pp->next != p) pp = pp->next;
                            pp->next = new;
                            new->next = p;
                        }
                    } else {                                    // 在后，不相邻
                        p->next = new;
                    }
                    break;
                }

                // 有后继节点
                if (p_endaddr < iniaddr) {                      // 新块在当前块之后，继续遍历
                    p = p->next;
                    continue;
                } else if (p_endaddr == iniaddr) {              // 邻接当前块尾部
                    if (p->next->iniaddr == endaddr) {          // 同时邻接下一块头部（三块合并）
                        Space *temp = p->next;
                        p->size += size + temp->size;
                        p->next = temp->next;
                        free(temp);
                        free(new);
                    } else {
                        p->size += size;
                        free(new);
                    }
                    break;
                } else if (endaddr == p->iniaddr) {             // 邻接当前块头部
                    p->iniaddr = iniaddr;
                    p->size += size;
                    free(new);
                    break;
                } else if (endaddr < p->iniaddr) {              // 完全在当前块之前，插入
                    Space *pp = mem;
                    while (pp->next != p) pp = pp->next;
                    pp->next = new;
                    new->next = p;
                    break;
                }
                // 理论上不会走到这里，因为重叠已经提前处理
            }
        }
    }
    Space *p=mem;
    while(p)
    {
        printf("%d %d %d", p->tag, p->iniaddr, p->size);
        p=p->next;
        if(p) putchar('\n');
    }
    return 0;
}