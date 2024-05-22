class Solution
{
    public:
        int majorityElement(vector<int> &nums)
        {
            int ele = -1, cnt = 0;
            int n = nums.size();
            for (int i = 0; i < nums.size(); i++)
            {
                if (cnt == 0)
                {
                    ele = nums[i];
                    cnt = 1;
                }
                else if (ele == nums[i])
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
            }
            int cnt1 = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == ele)
                {
                    cnt1++;
                }
            }
            if (cnt1 >= n / 2)
            {
                return ele;
            }
            return -1;
        }
};