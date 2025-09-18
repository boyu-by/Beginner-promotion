#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int id, next;
} node;

int main() 
{
    int N, k, p, M, x;
    cin >> N;
    
    node nodes[N+1];
    int prev[N+1];
    // 初始化
    for (int i = 1; i <= N; i++) 
    {
        nodes[i].id = i;
        nodes[i].next = -1;
        prev[i] = -1;
    }
    
    // 初始时只有1号同学在队列中
    nodes[1].next = -1;
    
    // 2~N号同学依次入列
    for (int i = 2; i <= N; i++) 
    {
        cin >> k >> p;

        if (p == 0) 
        { 
            if (prev[k]!=-1)
            {
                nodes[prev[k]].next=i;
                prev[i]=prev[k];
                nodes[i].next=k;
                prev[k]=i;
            }
            else
            {
                nodes[i].next=k;
                prev[k]=i;
                prev[i]=-1;
            }
        }
        else if (p==1)
        {
            nodes[i].next=nodes[k].next;
            if (nodes[k].next!=-1)
            {
                prev[nodes[k].next]=i;
            }
            nodes[k].next=i;
            prev[i]=k;
        }
    }
    
    // 删除操作
    cin >> M;
    for (int i = 0; i < M; i++) 
    {
        cin >> x;
        int prev_x = prev[x];
        if (prev_x!=-1)
        {
            nodes[prev_x].next=nodes[x].next;
            prev[nodes[x].next]=prev_x;
        }
        else
        {
            if (nodes[x].next!=-1)
            {
                prev[nodes[x].next]=-1;
            }
        }
        prev[x]=-1;
        nodes[x].next=-1;
    }
    //  输出
    for (int i =1;i<=N;i++)
    {
        if (nodes[i].next!=-1&&prev[i]==-1)
        {
            int curr=i;
            bool first=true;
            while (nodes[curr].next!=-1)
            {
                if (!first) cout<<" ";
                cout<<curr;
                curr=nodes[curr].next;
                first=false;
            }
            cout<<" "<<curr;
            break;
        }
    }
    return 0;
}