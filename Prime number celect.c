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

int main()
{
    int n;
    scanf("%d\n",&n);
    int arr[n];
    for (int j=0;j<n;j++)
    {
        scanf("%d",&(arr[j]));
    }
    for (int i=0;i<n;i++)
    {
        if(select_prime(arr[i])==1)
        {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}