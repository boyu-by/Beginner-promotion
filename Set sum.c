// 给定一个集合 s（集合元素数量 ≤30），求出此集合所有子集元素之和
#include<stdio.h>
#include<math.h>
int main()
{
    int num,s=0;
    long long sum=0;
    while (scanf("%d", &num) != EOF)
    {
        s ++;
        sum+=num;
    }
    long long result=(long long)pow(2,s-1)*sum;
    printf("%lld", result);
    return 0;
}