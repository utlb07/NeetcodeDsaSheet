class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            if(mp.find(-(i))!=mp.end())
            {
                ans=max(ans,abs(i));
            }
            mp[i]++;
        }
        return ans;
    }
};