class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.length();
        int cnt=0;
        for(auto i:words)
        {
            string p=i.substr(0,n);
            if(p==pref)
            {
                cnt++;
            }
        }
        return cnt;
    }
};