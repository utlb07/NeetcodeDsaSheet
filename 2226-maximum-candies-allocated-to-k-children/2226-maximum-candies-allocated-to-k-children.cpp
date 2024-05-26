class Solution
{
    public:
        bool fun(long long int mid, vector< int> &candies, long long int k)
        {
            long long int cnt = 0;
            for (auto it: candies)
            {
                cnt += it / mid;
            }
            return cnt >= k;
        }
    int maximumCandies(vector<int> &candies, long long k)
    {
        int n=candies.size();
        sort(candies.begin(), candies.end());
        long long low =1;
        long long high=*max_element(candies.begin(),candies.end());
        // for (auto &it: candies)
        // {
        //     high += it;
        // }
        long long ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (fun(mid, candies, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};