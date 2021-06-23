class Solution {
public:
     void lpstable(string s, vector<int>&lps)
    {
        int i=1;
        int len=0;
        while(i<s.size())
        {
                if(s[i]==s[len])
                {
                    lps[i]=len+1;
                    z++;
                    i++;
                }
             else
             if(len!=0)
             {
                  len=lps[len-1];
             }
             else       
                i++;
        }
    }
    void kmpsearch(string s,string p) {
       vector<int>lps(s.size()+1,0);
       lpstable(s,lps);
       int n=s.size();
       int m=p.size();
       int j=0,i=0;
       while(i<n)
       {
           if(s[i]==p[j])
           {
               i++;
               j++;
           }
           else
           if(j!=0)
           {
               j=lps[j-1];
               continue;
           }
           else
               i++;    
           if(j==m)
           {
                cout<<"pattern found at index: "<<i-j;
                j=lps[j-1];
           }
       }
    }
};
