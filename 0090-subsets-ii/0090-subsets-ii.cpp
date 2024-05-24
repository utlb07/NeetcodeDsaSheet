class Solution {
public:
    set<vector<int>> res;
    vector<int> path;
    
    void helper(int index, vector<int>& nums)
    {
        if(index==nums.size())
        {
            res.insert(path);
            return;
        }
        path.push_back(nums[index]);
        helper(index+1, nums);
        path.pop_back();
        helper(index+1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        helper(0, nums);
        vector<vector<int>> ans;
        for(vector<int> x : res)
        {
            ans.push_back(x);
        }
        return ans;
    }
};