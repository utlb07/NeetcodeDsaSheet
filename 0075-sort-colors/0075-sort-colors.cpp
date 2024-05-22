class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 2 0 2 1 1 0
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(low<=mid&&mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};