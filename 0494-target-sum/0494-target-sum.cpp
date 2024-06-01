class Solution {
public:
    int check(int index, int target, vector<int> &nums)
    {
        if(index<0&&target==0) return 1;
        if(index<0) return 0;
        int add=check(index-1,target-nums[index],nums);
        int sub=check(index-1,target+nums[index],nums);

        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        return check (n-1,target,nums);
    }
};