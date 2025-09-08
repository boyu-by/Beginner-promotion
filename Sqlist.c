#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct 
{
    int length;
    ElemType elem[MAXSIZE];
}Sqlist;
void Initlist(Sqlist *L)
{
    L->length=0;
    printf("初始化成功\n");
}

void printlist(Sqlist *L)
{
    for (int i =0;i<=L->length-1;i++)
    {
        printf("下面开始遍历\n");
        printf("%d ",L->elem[i]);
    }
    printf("\n");
}
int appendlist(Sqlist *L,ElemType e)
{
    if (L->length<MAXSIZE)
    {
        L->elem[L->length]=e;
        L->length++;
        return 1;
    }
    else 
    {
        printf ("顺序表满了");
        return 0;
    }
}
int insertlist(Sqlist *L,int i,ElemType e)
{
    if (i<1||i>L->length+1)
    {
        printf("插入位置不合法");
        return 0;
    }
    else if (L->length==MAXSIZE)
    {
        printf("顺序表满了");
        return 0;
    }
    else
    {
        for (int j=L->length;j>=i;j--)
        {
            L->elem[j]=L->elem[j-1];
        }
        L->elem[i-1]=e;
        L->length++;
        return 1;
    }
    
}
int deletelist(Sqlist*L,int i,ElemType *e)
{
    *e=L->elem[i-1];
    for (int j=i;j<L->length;j++)
    {
        L->elem[j-1]=L->elem[j];
    }
    L->length--;
    return 1;
}
int findlist(Sqlist *L,ElemType e)
{
    for (int i=0;i<L->length;i++)
    {
        if (e==L->elem[i])
        {
            return i+1;
        }
    }
    return 0;
}
int main()
{

}