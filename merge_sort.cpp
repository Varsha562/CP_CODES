#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&v,int l,int m,int r)
{
 vector<int>a,b;
 for(int i=l;i<=m;i++)
 a.push_back(v[i]);
 for(int i=m+1;i<=r;i++)
 b.push_back(v[i]);
 int i=0,j=0,k=l;
 while(i<a.size() && j<b.size())
 {
     if(a[i]<=b[j])
     v[k]=a[i],i++,k++;
     else
     if(a[i]>b[j])
     v[k]=b[j],j++,k++;
 }
 while(i<a.size())
 {
     v[k]=a[i];
     k++;
     i++;
 }
 while(j<b.size())
 {
     v[k]=b[j];
     k++;
     j++;
 }
}
void mergesort(vector<int>&v,int l,int r)
{
    if(l>=r)
    return;
    int m=(l+r)/2;
    mergesort(v,l,m);
    mergesort(v,m+1,r);
    merge(v,l,m,r);
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    mergesort(v,0,n-1);
    for(int i:v)
    cout<<i<<" ";
    return 0;
}
