class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        // for(int i=0;i<n;i++)
        // {
        //     int leftmax=0,rightmax=0;
        //     for(int j=i;j>=0;j--)
        //     {
        //         leftmax=max(leftmax,height[j]);
        //     }
        //     for(int j=i;j<n;j++)
        //     {
        //         rightmax=max(rightmax,height[j]);
        //     }
        //     ans+=min(rightmax,leftmax)-height[i];
        vector<int>leftmax(n,0);
        vector<int>rightmax(n,0);
        leftmax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        rightmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
        for(int i=0;i<n;i++)
        {
            ans+=min(leftmax[i],rightmax[i])-height[i];
        }
        return ans;
    }
};