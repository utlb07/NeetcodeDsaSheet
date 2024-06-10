class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        int ans=0;
        int i=0,j=0;
        while(j<n)
        {
            mp[s[j]]++;
           if(mp[s[j]]>=2)
            {
                while(mp[s[j]]>=2)
                {
                    mp[s[i]]--;
                    i++;
                }
               if(mp[s[i]]==0)
               {
                   mp.erase(mp[s[i]]);
               }
              
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};