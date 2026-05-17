#include <stdio.h>
#include <stdlib.h>

typedef struct OLNode
{
    int i, j;
    int e;
    struct OLNode *right, *down;
}OLNode, *OLink;

typedef struct
{
    OLink *rhead, *chead;
    int mu, nu, tu;
}CrossList;

int getV(int V[]);
void getMatrix(int V[], CrossList *M);
void printMatrix(CrossList *M);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    getchar();
    CrossList A, B;
    A.rhead=(OLink *)malloc((m)*sizeof(OLink));
    A.chead=(OLink *)malloc((n)*sizeof(OLink));
    B.rhead=(OLink *)malloc((m)*sizeof(OLink));
    B.chead=(OLink *)malloc((n)*sizeof(OLink));
    for(int i=0; i<m; i++)
    {
        A.rhead[i]=NULL;
        B.rhead[i]=NULL;
    }
    for(int j=0; j<n; j++)
    {
        A.chead[j]=NULL;
        B.chead[j]=NULL;
    }
    A.mu=m;
    A.nu=n;
    B.mu=m;
    B.nu=n;
    int V[m*n];
    A.tu=getV(V);
    getMatrix(V, &A);
    getchar();
    B.tu=getV(V);
    getMatrix(V, &B);
    // printMatrix(&A);
    // putchar('\n');
    // printMatrix(&B);
    // putchar('\n');
    for(int i=0; i<m; i++) // A'=A+B
    {
        OLNode *pa=A.rhead[i];
        OLNode *pb=B.rhead[i];
        if(pb == NULL) continue;
        while(pb != NULL)
        {
            if(pa == NULL || pa->j > pb->j)
            {
                OLNode *addNode=(OLNode *)malloc(sizeof(OLNode));
                addNode->e=pb->e;
                addNode->i=i;
                addNode->j=pb->j;
                OLNode *pin;
                pin=A.rhead[i];
                if(pin == NULL || pin->j > pb->j)
                {
                    addNode->right=pin;
                    A.rhead[i]=addNode;
                }
                else
                {
                    while(pin->right != pa) pin=pin->right;
                    addNode->right=pin->right;
                    pin->right=addNode;
                }
                pin=A.chead[pb->j];
                if(pin == NULL || pin->i > i)
                {
                    addNode->down=pin;
                    A.chead[pb->j]=addNode;
                }
                else
                {
                    while(pin->down != NULL && pin->down->i < i) pin=pin->down;
                    addNode->down=pin->down;
                    pin->down=addNode;
                }
                pb=pb->right;
            }
            else if(pa->j < pb->j) pa=pa->right;
            else // pa->j == pb->j
            {
                int newValue=pa->e+pb->e;
                if(newValue != 0) pa->e=newValue;
                else
                {
                    OLNode *pfree;
                    OLNode *pin;
                    pin=A.rhead[i];
                    if(pin == pa)
                    {
                        A.rhead[i]=pa->right;
                        pfree=pa;
                        pa=A.rhead[i];
                    }
                    else
                    {
                        while(pin->right != pa) pin=pin->right;
                        pin->right=pa->right;
                        pfree=pa;
                        pa=pin;
                    }
                    pin=A.chead[pb->j];
                    if(pin == pfree) A.chead[pb->j]=pfree->down;
                    else
                    {
                        while(pin->down != pfree) pin=pin->down;
                        pin->down=pfree->down;
                    }
                    free(pfree);
                }
                pb=pb->right;
            }
        }
        // printMatrix(&A);
        // putchar('\n');
    }
    printMatrix(&A);
    return 0;
}

int getV(int V[])
{
    char c;
    int num=0;
    int t=0;
    int sign=1;
    while((c=getchar()))
    {
        if(c == '\n' && t == 0 && num == 0) break;
        if(c == ' ' || c == '\n')
        {
            V[t++]=num*sign;
            num=0;
            sign=1;
            if(c == ' ') continue;
            else break;
        }
        if(c == '-')
        {
            sign=-1;
            continue;
        }
        num*=10;
        num+=c-'0';
    }
    return t;
}

void getMatrix(int V[], CrossList *M)
{
    int pos=0;
    for(int i=0; i<M->mu; i++)
    {
        for(int j=0; j<M->nu; j++)
        {
            int num;
            scanf("%d", &num);
            if(num == 1)
            {
                OLNode *newNode;
                newNode=(OLNode *)malloc(sizeof(OLNode));
                newNode->e=V[pos++];
                newNode->i=i;
                newNode->j=j;
                if(M->rhead[i] == NULL)
                {
                    newNode->right=M->rhead[i];
                    M->rhead[i]=newNode; //No head node here in CrossLink, M->rhead[i] is exactly the first non-0 element.
                }
                else
                {
                    OLink pin;
                    for(pin=M->rhead[i]; pin->right != NULL; pin=pin->right);
                    newNode->right=pin->right;
                    pin->right=newNode;
                }
                if(M->chead[j] == NULL)
                {
                    newNode->down=M->chead[j];
                    M->chead[j]=newNode;
                }
                else
                {
                    OLink pin;
                    for(pin=M->chead[j]; pin->down != NULL; pin=pin->down);
                    newNode->down=pin->down;
                    pin->down=newNode;
                }
            }
        }
    }
    return;
}

void printMatrix(CrossList *M)
{
    int spaceFlag=0;
    for(int i=0; i<M->mu; i++)
    {
        OLNode *pin=M->rhead[i];
        while(pin != NULL)
        {
            if(spaceFlag == 0)
            {
                spaceFlag=1;
                printf("%d", pin->e);
            }
            else printf(" %d", pin->e);
            pin=pin->right;
        }
    }
    putchar('\n');
    for(int i=0; i<M->mu; i++)
    {
        OLNode *pin=M->rhead[i];
        for(int j=0; j<M->nu; j++)
        {
            if(pin != NULL && pin->j == j)
            {
                printf("1");
                pin=pin->right;
            }
            else printf("0");
            if(j != M->nu-1) putchar(' ');
        }
        if(i != M->mu-1) putchar('\n');
    }
}

// Time Complexity: O(ta+tb)