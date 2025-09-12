#include <stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef int ElemType;
    typedef struct DNode
    {
        ElemType data;
        struct DNode *prior;
        struct DNode *next;
    }DNode;

    DNode* initlist()
    {
        DNode *L=(DNode*)malloc(sizeof (DNode));
        L->next=NULL;
        L->prior=NULL;
        return L;
    }

    int headinsert(DNode*L,ElemType x)
    {
        DNode *p=(DNode*)malloc(sizeof(DNode));
        p->data =x;
        p->next=L->next;
        p->prior=L;
        if (L->next!=NULL)
        {
            L->next->prior=p;
        }
        L->next=p;
        return 1;
    }

    DNode* gettail(DNode*L)
    {
        DNode *p=L;
        while (p->next!=NULL)
        {
            p=p->next;
        }

    }

    DNode* tailinsert(DNode*tail,ElemType x)
    {
        DNode *p=(DNode*)malloc(sizeof(DNode));
        p->data=x;
        p->prior=tail;
        tail->next=p;
        p->next=NULL;
        return p;
    }
    int listinsert(DNode*L,int i,ElemType x)
    {
        DNode *p=L;
        int j=0;
        while (p!=NULL&&j<i-1)
        {
            p=p->next;
            j++;
        }
        if (p==NULL)
        {
            return 0;
        }
        DNode *s=(DNode*)malloc(sizeof(DNode));
        s->data=x;
        s->next=p->next;
        s->prior=p;
        if (p->next!=NULL)
        {
            p->next->prior=s;
        }
        p->next=s;
        return 1;
    }

    int deletNode(DNode *L,int x)
    {
        DNode *p=L;
        int i=0;
        while (i<x-1)
        {
            p=p->next;
            i++;
            if (p==NULL)
            {
                return 0;
            }
        }
        if (p->next==NULL)
        {
            return 0;
        }
        DNode *q=p->next;
        p->next=q->next;
        if(q->next!=NULL)
        {
            q->next->prior=p;
        }
        free(q);
        return 1;
    }
    




