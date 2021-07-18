//queue-reconstruction-by-height
class Solution {
public:
    int n;
    vector<int>BIT;
    static bool comp(vector<int>a,vector<int>b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]>b[1];
    }
    void update(int x,int v)
    {
        for(int i=x;i<=n;i+=i&-i)
            BIT[i]+=v;
            
    }
    int sum(int x)
    {
        int sum=0;
        for(int i=x;i>0;i-=i&-i)
            sum+=BIT[i];
        return sum;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n=people.size();
        BIT=vector<int>(n+1,0);
        vector<vector<int>> ans(n, vector<int>());
        for(int i=2;i<=n;i++)
            update(i,1);
        sort(people.begin(),people.end(),comp);
        for(int i=0;i<n;i++)
        {
            int l=0,r=n;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(sum(mid+1)<people[i][1])
                    l=mid+1;
                else
                    r=mid;
            }
            ans[l]=people[i];
            update(l+1,-1);
        }
        return ans;
    }
};
