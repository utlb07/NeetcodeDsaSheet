class Solution {
public:
    int longestPalindrome(string s) {
            int ans = 0;
        unordered_map<char, int> mp;
        for (auto a : s) mp[a]++;
        bool odd = false;
        for (auto x : mp) {
            if(x.second % 2 == 0) {
                ans += x.second; 
            } else {
                ans += (x.second - 1); 
                odd = true;
            }
        }
        return ans + odd;
    }
};