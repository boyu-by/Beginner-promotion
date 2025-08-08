#include<stdio.h>

int select_prime(int x)
{
    if (x < 2) return 0; 
    if (x == 2) return 1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }    
    return 1;
}

int next_prime(int x)
{
    int i=x+1;
    while (select_prime(i)==0)
    {
        i++;
    }
    return i;
}

int main()
{
    int L;
    int n=0, sum=0;
    int current_prime = 2; // 从第一个素数开始
    
    scanf("%d",&L);
    
    // 持续寻找素数，直到加上下一个素数会超过L
    while (sum + current_prime <= L) 
    {
        printf("%d\n", current_prime);
        sum += current_prime;
        n++;
        current_prime = next_prime(current_prime);
    }
    
    printf("%d", n);
    return 0;
}