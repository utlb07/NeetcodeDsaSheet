class Solution {
public:
    int dp[2501][2501];
    int fun(int prev, int id, vector<int>& nums) {
        if (id >= nums.size()) {
            return 0;
        }
        if (prev != -1 && dp[id][prev] != -1) {
            return dp[id][prev];
        }
        int take = 0, nottake = 0;
        if (prev == -1 || nums[id] > nums[prev]) {
            take = 1 + fun(id, id + 1, nums);
        }
        nottake = fun(prev, id + 1, nums);
        int result = max(take, nottake);
        if (prev != -1) {
            dp[id][prev] = result;
        }
        return result;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return fun(-1, 0, nums);
    }
};
