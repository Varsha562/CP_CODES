#include<bits/stdc++.h>
using namespace std;
string solve(string s)
{
    if(s.size()==1)
    {
        return s;
    }
    stack<int>st;
    int i;
    char boolexp=s[0];
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='?')
        {
            st.push(i);
            break;
        }
    }
    i++;
    while(i<s.size())
    {
        if(st.size()==1 && s[i]==':')
        {
         int curr=st.top();
         st.pop();
        // cout<<curr+1<<" "<<i-curr-1<<"\n";
         string ep1=solve(s.substr(curr+1,i-curr-1));
         string ep2=solve(s.substr(i+1));
         //cout<<ep1<<" "<<ep2<<"\n";
         if(boolexp=='T')
         {
             return ep1;
         }
         else
         if(boolexp=='F')
         {
             return ep2;
         }
        }
        else
        if(s[i]==':')
        {
            st.pop();
        }
        else
        if(s[i]=='?')
        {
            st.push(i);
        }
        i++;
    }
    return s;
}
int main()
{
    string s;
    cin>>s;
    cout<<solve(s)<<"\n";
}
