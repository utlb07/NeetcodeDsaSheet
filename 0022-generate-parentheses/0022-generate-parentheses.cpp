class Solution {
public:
    
    void solve(int open,int end,string s,vector<string>&ans,int n)
    {
        if(size(s)==2*n)
        {
            ans.push_back(s);
            return;
        }
        if(open<n)
        {
            solve(open+1,end,s+'(',ans,n);
        }
        if(open>end)
        {
            solve(open,end+1,s+')',ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,"",ans,n);
        return ans;
    }
};