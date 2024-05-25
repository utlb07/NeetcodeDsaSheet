class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mid>0&&nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }
            else if(nums[mid]>nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return nums[low];
    }
};