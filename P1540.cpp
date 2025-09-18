#include <bits/stdc++.h>
using namespace std;
#define N 1003
int Hash[N]={0};
typedef struct myqueue
{
    int data[N];
    int head,rear;
    bool init()
    {
        head=rear=0;
        return true;
    }
    int size()
    {
        return ((rear-head+N)%N);
    }
    bool empty()
    {
        if (size()==0) return true;
        return false;
    }
    bool push(int e)
    {
        if ((rear+1)%N==head)
        {
            return false;
        }
        data [rear]=e;
        rear=(rear+1)%N;
        return true;
    }
    bool pop(int &e)
    {
        if (head==rear)
        {
            return false;
        }
        e=data[head];
        head=(head+1)%N;
        return true;
    }
    int front()
    {
        return data[head];
    }
}Q;

int main()
{
    Q myQ;
    myQ.init(); 
    int m,n;
    cin>>m>>n;
    int sum=0;
    while (n--)
    {
        int temp;
        cin>>temp;
        if (Hash[temp]==0)
        {
            myQ.push(temp);
            Hash[temp]=1;
            sum++;
            while(myQ.size()>m)
            {
                int x;
                myQ.pop(x);
                Hash[x]=0;
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}