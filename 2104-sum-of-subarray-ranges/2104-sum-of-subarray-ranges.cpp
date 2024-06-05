class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n= nums.size();
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            int maxi=nums[i],mini=nums[i];
            for(int j=i;j<n;j++)
            {
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};