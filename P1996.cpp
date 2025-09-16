#include <bits/stdc++.h>
typedef int ElemType;
typedef struct Node 
{
    ElemType data;
    struct Node *next;
} node; 

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    node *head,*now,*p,*prev;
    head=new node;
    head->data=1;
    head->next=NULL;
    now = head;
    for (int i=2;i<=n;i++)
    {
        p=new node;
        p->data=i;
        p->next=NULL;
        now->next=p;
        now=p;
    }
    now->next=head;
    now=head;
    prev=head;
    while ((n--)>1)
    {
        for (int i=1;i<m;i++)
        {
            prev=now;
            now=now->next;
        }
        printf("%d ",now->data);
        prev->next=now->next;
        now=now->next;
    }
    printf("%d",now->data);
    delete (now);
    return 0;
}