#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        s=max(s,v[i]);
    }
    int count=(int)log2(s)+1;
    vector<int>set(count,0),not_set(count,0);
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((1<<i) & v[j])
            set[i]++;
            else
            not_set[i]++;
        }
    }
    int ans=0;
    for(int i=0;i<count;i++)
    {
        int total=set[i]*not_set[i];
        ans+=pow(2,i)*total;
    }
    cout<<ans;
}
