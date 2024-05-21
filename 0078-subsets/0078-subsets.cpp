class Solution
{
    public:
        vector<vector < int>> ans;
    void fun(vector<int> &nums, int id, int n, vector<int> use)
    {
        if (id == n)
        {
            ans.push_back(use);
            return;
        }
        use.push_back(nums[id]);
        fun(nums, id + 1, n, use);
        use.pop_back();
        fun(nums, id + 1, n, use);
    }
    vector<vector < int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> use;
        fun(nums, 0, n, use);
        return ans;
    }
};