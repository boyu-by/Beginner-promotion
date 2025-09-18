#include <bits/stdc++.h>
using namespace std;
int Hash[1003]={0};
queue<int>words;
int main()
{
    int m,n;
    cin>>m>>n;
    int sum=0;
    while(n--)
    {
        int temp;
        cin>>temp;
        if (!Hash[temp])
        {
            sum++;
            words.push(temp);
            Hash[temp]=1;
            while (words.size()>m)
            {
                Hash[words.front()]=0;
                words.pop();
            }
        }
    }
    cout<<sum;
    return 0;
}