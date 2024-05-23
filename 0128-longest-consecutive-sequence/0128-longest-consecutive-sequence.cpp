class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            int n = nums.size();
            unordered_map<int, int> mp;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                mp[nums[i]]++;
            }
            int i = 0, j = 0;
            for (int j = 0; j < n; j++)
            {

                if (mp.count(nums[j] - 1)==true)
                {
                    continue;
                }
                int ele = nums[j];
                int cnt = 0;
                while (mp.count(ele))
                {
                    cnt++;
                    ele++;
                    ans = max(ans, cnt);
                }
            }

            return ans;
        }
};