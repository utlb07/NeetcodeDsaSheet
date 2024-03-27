class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//          int i = 0, j = 0;
//         int cnt = 0;
//         int n = nums.size();
//         int prod = 1;
//         if (k <= 1) {
//             return 0;
//         }
//         while (j < n) {
//             prod *= nums[j];
//             while (prod >= k) {
//                 prod /= nums[i];
//                 i++;
//             }

//           if(prod<k)
//             cnt += (j - i + 1);
//             j++;
//         }
//         return cnt;
         int i=0,j=0;
        int cnt=0;
        int n=nums.size();
        int prod=1;
        if(k<=1)
        {
            return 0;
        }
           while( j < n)
        {
            
            prod*=nums[j];
            while(prod>=k)
            {
                prod=prod/nums[i];
                i++;
            }
            if(prod<k)
            {
                cnt+=j-i+1;
            }
            j++;
        }
        return cnt;
    }
};