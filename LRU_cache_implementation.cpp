#include<bits/stdc++.h>
using namespace std;
list<int>dq;
map<int,list<int>::iterator>m;
void check(int k,int n)
{
    if(m.find(k)==m.end())
    {
        if(dq.size()==n)
        {
            int last=dq.back();
            dq.pop_back();
            m.erase(last);
        }
    }
    else
    dq.erase(m[k]);
    dq.push_front(k);
    m[k]=dq.begin();
}
int main()
{
    int t,n;
    cin>>t>>n;
    while(t--)
    {
    int k;
    cin>>k;
    check(k,n);
    for(auto it:dq)
    cout<<it<<" ";
    cout<<"\n";
    }
}
