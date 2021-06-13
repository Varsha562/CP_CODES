#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return a==0?b:gcd(b%a,a);
}
int main()
{
   int n,d;
   cin>>n>>d;
   vector<int>v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   d=d%n;
   int g=gcd(n,d);
   int k=0;
   for(int i=0;i<g;i++)
   {
       int j=i;
       while(1)
       {
           int k=j+d;
           if(k>=n)
           k-=n;
           if(k==i)
           break;
           v[j]=v[k];
           j=k;
       }
       v[j]=v[i];
   }
   for(int i:v)
   cout<<i<<" ";
   return 0;
}
