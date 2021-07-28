#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&v,int x)
{
    int l=0,r=v.size()-1,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(v[mid]<x)
        l=mid+1;
        else
        r=mid;
    }
    if(l==r)
    return l;
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<int>v;
    v.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        if(a[i]<v.back())
        {
            v[binary_search(v,a[i])]=a[i];
        }
        else
        v.push_back(a[i]);
    }
    cout<<v.size()<<"\n";
    for(int i:v)
    cout<<i<<" ";
}
