#include<stdio.h>
int select_prime(int x)
{
    if (x < 2) return 0; 
    if (x == 2) return 1;
    for(int i=2;i*i<x;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }    
    return 1;
}
int max(int a,int b)
{
    if (a>b) return a;
    else return b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
    {
        if (select_prime(i)==1&&n%i==0&&select_prime(n/i)==1)
        {
          printf("%d",max(i,n/i));
          break;  
        }
    }
    return 0;
}

