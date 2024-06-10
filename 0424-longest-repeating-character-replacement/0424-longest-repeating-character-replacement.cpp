class Solution {
public:
    int len(int arr[],int n)
    {
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>maxi)
            {
                maxi=arr[i];
            }
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int n=s.length();
        unordered_map<char,int>mp;
        int i=0,j=0;
        int ans=-1;
        int maxi=0;
        while(j<n)
        {
            mp[s[j]]++;
            maxi=max(maxi,mp[s[j]]);
            if(j-i+1-maxi>k)
            {
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};