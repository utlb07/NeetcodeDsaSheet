class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int ans=INT_MIN;
        int s=0;
        sort(nums.begin(),nums.end());
        while(i<j)
        {
            s=(nums[i]+nums[j]);
            i++;
            j--;
           ans=max(ans,s);
        }
        return ans;
    }
};