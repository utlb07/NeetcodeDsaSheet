class Solution {
public:
    int first(vector<int>& nums, int target)
    {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    int last(vector<int>& nums, int target)
    {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // int x=first(nums,target);
        // int y=last(nums,target);
        // return {x,y
        int n=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
         int m=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(n==m)
        {
            return {-1,-1};
        }
        return {n,m-1};
    }
};