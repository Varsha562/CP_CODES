#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
vector<int>adj[100001];
vector<bool>vis(100001,false);
ll ans = 0;
ll dp[100001][2];
vector<pair<ll,ll>>v(100001);
void dfs(ll x)
{
    dp[x][0]=0,dp[x][1]=0;
    vis[x]=true;
    for(ll child:adj[x])
    {
      if(vis[child]==true)
      continue;
      dfs(child);
      dp[x][0]+=max(abs(v[x].first-v[child].first)+dp[child][0],abs(v[x].first-v[child].second)+dp[child][1]);
      dp[x][1]+=max(abs(v[x].second-v[child].first)+dp[child][0],abs(v[x].second-v[child].second)+dp[child][1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            ll l,r;
            cin>>l>>r;
            v[i].first=l,v[i].second=r;
        }
        fill(adj + 1, adj + n + 1, vector<int>());
          for(int i=1;i<=n;i++)
        {
            vis[i]=false;
            dp[i][0]=0;
            dp[i][1]=0;
        }
        ans=0;
        for(int i=0;i<n-1;i++)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);
        cout<<max(dp[1][0],dp[1][1])<<"\n";
    }
      return 0;
}
