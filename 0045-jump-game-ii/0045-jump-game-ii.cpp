class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        if(nums[0]==0)
        {
            return 0;
        }
        if(n==1)
        {return 0;
        }
        int maxreach=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            maxreach=max(maxreach,i+nums[i]);
             if(maxreach>=n-1)
            {
                return cnt+1;
            }
            if(i==curr)
            {
                curr=maxreach;
                cnt++;
            }
           
        }
        return -1;
    }
};