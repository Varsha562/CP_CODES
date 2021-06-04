//factors of n 
#include <bits/stdc++.h>
#define ll long long int
#define mod 998244353
using namespace std;
vector<int>factor(1000001,1);
void factors(int n)
{
    int c=0;
    for(int i=2;i<=n;i++)
    for(int j=i;j<=n;j+=i)
    factor[j]++;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
      int n;
      cin>>n;
      if(n==1)
      {
          cout<<"1\n";
          return 0;
      }
      factors(n);
 return 0;
}
