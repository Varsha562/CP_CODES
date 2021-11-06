#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100000];
vector<int>ans;
int dfs(vector<int>&res,int *mincost,int pathsize,int index,int target_index,vector<string>&names,vector<string>&path,int diff_words)
{
    if(names[index]!=path[target_index])
    diff_words++;
    if(target_index==pathsize-1)
    {
        if(*mincost>diff_words)
        {
            *mincost=diff_words;
            ans=res;
        }
        return *mincost;
    }
    for(int child:adj[index])
    {
        res.push_back(child);
        dfs(res,mincost,pathsize,child,target_index+1,names,path,diff_words);
        res.pop_back();
    }
    return *mincost;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<string>names(n);
    for(int i=0;i<n;i++)
    cin>>names[i];
    int pathsize;
    cin>>pathsize;
    vector<string>path(pathsize);
    vector<int>result;
    for(int i=0;i<pathsize;i++)
    {
        cin>>path[i];
    }
    int min_val=INT_MAX;
    for(int i=0;i<n;i++)
    {
        vector<int>res;
        res.push_back(i);
        int mincost=min_val;
        int x= dfs(res,&mincost,pathsize,i,0,names,path,0);
        //cout<<x<<"\n";
        if(x<min_val)
        {
            min_val=x;
        }
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}
