class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        int cnt=0;
        int ans=0;
        int i=0,j=0;
        while(j<n)
        {
            mp[s[j]-'a']++;
            while(mp[0]>=1&&mp[1]>=1&&mp[2]>=1)
            {
                ans+=n-j;
                mp[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};