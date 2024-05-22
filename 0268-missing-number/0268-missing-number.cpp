class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int s=0,s1=0;
        for(int i=0;i<=n;i++)
        {
            s+=i;
        }
        for(int i=0;i<n;i++)
        {
            s1+=nums[i];
        }
        return s-s1;
    }
};