class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                cnt++;
                ans=max(ans,cnt);
            }
            else
            {
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        return ans;
    }
};