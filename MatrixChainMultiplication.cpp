#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n),r(n),c(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    for(int i=1;i<=n-1;i++)
    r[i]=v[i-1],c[i]=v[i];
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        dp[i][j]=INT_MAX;
    }
    for(int i=0;i<=n;i++)
    dp[i][i]=0;
    for(int length=2;length<=n-1;length++)
    {
        for(int i=1;i<=n-length;i++)
        {
        int j=i+length-1;
        for(int k=i;k<j;k++)
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+r[i]*c[k]*c[j]);
        }
    }
    cout<<dp[1][n-1];
}
