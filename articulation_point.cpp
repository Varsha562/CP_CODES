#include<bits/stdc++.h>
using namespace std;
vector<int>par(100001,-1),low(100001,INT_MAX),tin(100001,-1),vis(100001,0);
vector<int>adj[100001];
int dis=0,x;
int dfs(int v,int par)
{
    tin[v]=dis;
    low[v]=dis;
    dis++;
    x=0;
    for(int child:adj[v])
    {
        if(child==par)
        continue;
        if(vis[child])
        low[v]=min(tin[child],low[v]);
        else
        {
            dfs(child,v);
            low[v]=min(low[v],low[child]);
            if(low[child]>=tin[v] && par!=-1)
            return v;
            x++;
        }
    }
    if(p==-1 && x>1)
     return v;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    for(int i=0;i<n;i++)
    if(tin[i]==-1)
    dfs(i,-1);
}
