class Solution {
public:
    bool fun(vector<int>&nums,int h,int mid)
    {
        int sum=0;
       long long int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
           cnt+=(nums[i]/mid);
            if(nums[i]%mid!=0){
                cnt++;
            }
            
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int low=1,high=piles[n-1];
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(fun(piles,h,mid)==1)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            
        }
        return ans;
    }
};