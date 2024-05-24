class Solution {
public:
    void fun(vector<int>&nums,int tar,int id,vector<vector<int>>&ans,int s,vector<int>&out)
    {
        if(s==tar)
        {
            ans.push_back(out);
            return;
        }
        if(id>=nums.size()||s>tar)
        {
            return;
        }
        out.push_back(nums[id]);
        s+=nums[id];
        fun(nums,tar,id,ans,s,out);
        out.pop_back();
        s-=nums[id];
        fun(nums,tar,id+1,ans,s,out);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>a;
        fun(nums,tar,0,ans,0,a);
        return ans;
        
    }
};