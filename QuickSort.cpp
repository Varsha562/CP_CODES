#include<bits/stdc++.h>
using namespace std;
//pivot at the starting
int partition(vector<int>&v,int l,int h)
{
   int i=l-1;
   int pivot=v[h];
   for(int j=l;j<h;j++)
   {
       if(v[j]<pivot)
       {
           i++;
           swap(v[j],v[i]);
       }
   }
   swap(v[h],v[i+1]);
   return i+1;
}
void quicksort(vector<int>&v,int l,int h)
{
    if(l<h)
    {
    int j=partition(v,l,h);
    quicksort(v,l,j-1);
    quicksort(v,j+1,h);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    quicksort(v,0,n-1);
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
    return 0;
}
