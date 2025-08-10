// 现在有 n(n≤1000) 位评委给选手打分，分值从 0 到 10。
// 需要去掉一个最高分，去掉一个最低分（如果有多个最高或者最低分，也只需要去掉一个），剩下的评分的平均数就是这位选手的得分。
// 现在输入评委人数和他们的打分，请输出选手的最后得分，
// 精确到 2 位小数。
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    double sum=0;
    double a[n];
    for (int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
        sum+=a[i];
    }
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                double temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    sum=sum-a[0]-a[n-1];
    printf("%.2lf",sum/(n-2));
    return 0;
}