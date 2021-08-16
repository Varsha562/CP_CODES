#include<bits/stdc++.h>
using namespace std;
bool ispal(string str)
{
    string st="";
    for(int a=str.size()-1;a>=0;a--)
    st+=str[a];
    return (st==str);
}
void decompose(vector<vector<string>>&v,vector<string>&x,int n,string s,int i)
{
    if(i>=n)
    {
        v.push_back(x);
        return;
    }
    for(int j=i;j<n;j++)
    {
        if(ispal(s.substr(i,j-i+1)))
        {
            x.push_back(s.substr(i,j-i+1));
            decompose(v,x,n,s,j+1);
            x.pop_back();
        }
    }
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<string>>v;
    vector<string>x;
    decompose(v,x,n,s,0);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        cout<<v[i][j]<<" ";
        cout<<"\n";
    }
}
