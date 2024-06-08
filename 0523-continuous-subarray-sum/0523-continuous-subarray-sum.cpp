class Solution
{
    public:
        bool checkSubarraySum(vector<int> &nums, int k)
        {
            int s = 0;
            unordered_map<int, int> mp;
            mp[0] = -1;
            int j=0;
           while(j<nums.size())
            {
                s += nums[j];
                int rem = s % k;
                if (mp.find(rem) != mp.end())
                {
                    if (j - mp[rem] >= 2)
                    {
                        return true;
                    }
                }
                else
                {
                    mp[rem] = j;
                }
               j++;
            }
            return false;
        }
};