class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        int n=s.length();
        int m=t.length();
        int ans=0;
        int maxi=1;
        int i=0,j=0;
        int cost=0;
        while(i<n&&j<m)
        {
           cost+=abs(s[j]-t[j]);
            while(cost>maxcost)
            {
                cost-=abs(s[i]-t[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};