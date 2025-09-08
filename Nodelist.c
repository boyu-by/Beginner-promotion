//链表
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;  
}Node;

Node *Initlist()
{
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}

int insertHead (Node *L,ElemType e)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
    return 1;
}

void printlist(Node *L)
{
    Node *p=L->next;
    while (p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}

Node* get_tail(Node *L)
{
    Node *p=L;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}

Node* insertTail(Node *Tail,ElemType e)
{
    Node *p=(Node *)malloc(sizeof(Node));
    Tail->next=p;
    p->data=e;
    p->next=NULL;
    return p;
}

int insertNode(Node *L,int pos,ElemType e)
{
    Node *p=L;
    int i=0;
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if (p==NULL)
        {
            return 0;
        }   
    }
    Node *q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}

int deletNode(Node *L,int pos)
{
    Node *p=L;
    int i=0;
    while (i<pos-1)
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
    Node *q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}

int lenth_list(Node *L)
{
    int i=0;
    Node *p=L;
    while (p!=NULL)
    {
        p=p->next;
        i++;
    }
    return i;//头节点也算
}

void free_list(Node *L)
{
    Node *p=L->next;
    Node *q;
    while (p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}


int main ()
{
    Node *list=Initlist();
    return 0;
}