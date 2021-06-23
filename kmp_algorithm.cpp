class Solution {
public:
     void lpstable(string s, vector<int>&lps)
    {
        int i=1;
        while(i<s.size())
        {
            int z=1;
                if(s[i]==s[z-1])
                {
                    lps[i]=z;
                    z++;
                    i++;
                }
             else
             if(z!=1)
             {
                  z=lps[z-1];
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
