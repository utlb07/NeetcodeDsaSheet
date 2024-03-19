class Solution {
public:
    int f(int id,vector<int>&nums,vector<int>&dp)
    {
        if(id<0)
        {
            return 0;
        }
        if(dp[id]!=-1)
        {
            return dp[id];
        }
        int take=nums[id]+f(id-2,nums,dp);
        int nottake=f(id-1,nums,dp);
        return dp[id]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
		if(n==1)return nums[0];
		vector<int>nums1,nums2,dp1(n-1,-1),dp2(n-1,-1);
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                nums1.push_back(nums[i]);
            }
             if(i!=n-1)
            {
                nums2.push_back(nums[i]);
            }
        }
        return max(f(n-2,nums1,dp1),f(n-2,nums2,dp2));
    }
};