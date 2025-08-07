#include<stdio.h>
int include_num(int a[],int len,int num)
{
    for (int k=0;k<len;k++)
    {
        if (a[k]==num)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    int answer = 0;
    scanf("%d", &n);//表示数字个数
    int a[n];//数组a用来存储输入的数字
    int used[20001] = {0}; // 用于标记是否已经使用过的数字 
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);//输入数字
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0;j<i;j++)
        {
            int num = a[i] + a[j]; //计算两个数字的和
            if(include_num(a,n,num)&&!used[num])
            {
                answer++;
                used[num] = 1; // 标记这个和已经被使用过
            }
        }
    }
    printf("%d",answer);
    return 0;
}