class Solution {
public:
     void lpstable(string s, vector<int>&lps)
    {
        int i=1;
        while(i<s.size())
        {
            bool flag=0;
            int z=1;
                while(s[i]==s[z-1])
                {
                    flag=1;
                    lps[i]=z;
                    z++;
                    i++;
                }
            if(flag==0)
                i++;
        }
        //for(int x:lps)
        //cout<<x<<" ";
         //cout<<"\n";
    }
    string shortestPalindrome(string s) {
        vector<int>lps(s.size()+1,0);
        lpstable(s,lps);
        int n=s.size();
        string sr="";
        for(int i=n-1;i>=0;i--)
            sr+=s[i];
        int j=0,i=0;
            while(j<n)
            {
                if(s[j+1]==sr[i])
                {
                    i++;
                    j++;
                }
                else
                {
                   if(j!=lps[j])
                   {
                       j=lps[j];
                       continue;
                   }
                    else
                    i++;    
                }
                if(i>=n)
                    break;
            }
        //cout<<j+1<<endl;
        for(int x=j+2;x<=n;x++)
            sr+=s[x-1];
        //cout<<sr<<"\n";
        return sr;
    }
};
