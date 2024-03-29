class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
     int i=0,j=0;
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int n=nums.size();
        long long ans=0;
        while(j<n)
        {
            mp[nums[j]]++;
            while(mp[maxi]>=k)
            {
                ans+=n-j;
                mp[nums[i]]--;
                
                i++;
            }
            j++;
        }
        return ans;
    }
};