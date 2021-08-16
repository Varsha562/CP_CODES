#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        dp[i][j]=9999;
    }
    for(int i=0;i<=n;i++)
    dp[i][i]=0;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        dp[i][i+1]=0;
        else
        dp[i][i+1]=1;
    }
    for(int length=3;length<=n;length++)
    {
        for(int i=0;i<=n-length;i++)
        {
        int j=i+length-1;
        if(s[i]==s[j] && dp[i+1][j-1]==0)
        dp[i][j]=0;
        else
        {
        for(int k=i;k<j;k++)
        {
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
        }
        }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    cout<<dp[0][n-1];
}
