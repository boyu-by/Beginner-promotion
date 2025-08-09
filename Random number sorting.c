#include<stdio.h>
int main()
{
   int n;
   scanf("%d\n",&n);
   int a[n];
   for (int i=0;i<n;i++)
   {
        scanf("%d",&a[i]);
   }
   for (int i=0;i<n;i++)
   {
       for (int j=0;j<n-1-i;j++)
       {
           if (a[j]>a[j+1])
           {
               int temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
       }
   }
   int b[n];
   int size=0;
   b[0]=a[0];
   size++;
   for (int i=1;i<n;i++)
   {
        if (a[i]!=a[i-1])
        {
            b[size]=a[i];
            size++;
        } 
   }
   printf("%d\n",size);
   for (int i=0;i<size;i++)
   {
       printf("%d ",b[i]);
   }
   return 0;
}