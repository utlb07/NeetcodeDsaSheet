class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i>ans){
                return 0;
            }
            ans=max(ans,nums[i]+i);
        }
        return 1;
    }
};