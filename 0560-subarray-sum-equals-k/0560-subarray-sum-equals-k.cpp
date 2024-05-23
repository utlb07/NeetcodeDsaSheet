class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int s=0;
        int cnt=0;
        while(j<n)
        {
            s+=nums[j];
            if(s==k)
            {
                cnt++;
            }
            if(mp.find(s-k)!=mp.end())
            {
                cnt+=mp[s-k];
            }
            mp[s]++;
            j++;
        }
        return cnt;
    }
};