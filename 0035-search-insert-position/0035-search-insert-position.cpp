class Solution {
public:
    int searchInsert(vector<int>& nums, int tar) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==tar)
            {
                return mid;
            }
            else if(nums[mid]<tar)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
        // 1 3 5 6
        //0
        //
    }
};