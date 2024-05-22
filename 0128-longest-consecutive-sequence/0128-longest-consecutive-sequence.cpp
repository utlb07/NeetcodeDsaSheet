class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            int n = nums.size();
            if (n == 0)
            {
                return 0;
            }
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++)
            {
                mp[nums[i]]++;
            }
            int ans = 1;
            for (int i = 0; i < n; i++)
            {
                if (mp.count(nums[i] - 1))
                {
                    continue;
                }
                int x = nums[i];
                cout << x << endl;
                int cnt = 0;
                while (mp.count(x))
                {
                    cnt++;
                    x++;
                    ans = max(cnt, ans);
                }
            }
            return ans;
        }
};