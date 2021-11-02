#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
bool solve(string s1,string s2)
{
     int n=s1.size();
    map<char,char>m;
    for(int i=0;i<n;i++)
    {
        if(m.find(s1[i])!=m.end() && m[s1[i]]!=s2[i])
        return false;
        m[s1[i]]=s2[i];
    }
    vector<bool>vis(100);
    vis[m.begin()->first]=1;
    int x=m.begin()->second;
    while(m.find(x)!=m.end())
    {
        if(vis[x]==1)
        return false;
        vis[x]=1;
        x=m[x];
    }
    return true;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<solve(s1,s2);
}
