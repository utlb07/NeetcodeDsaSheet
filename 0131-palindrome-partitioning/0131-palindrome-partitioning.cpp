class Solution
{
    public:
        bool palindrom(string s, int i, int j)
        {
            while (i <= j)
            {
                if (s[i++] != s[j--])
                {
                    return false;
                }
            }

            return true;
        }
    void solve(vector<vector < string>> &ans, string s, vector< string > &new1, int i)
    {
        if (i == s.size())
        {
            ans.push_back(new1);
        }
        for (int id = i; id < s.size(); id++)
        {

            if (palindrom(s, i, id))
            {
                new1.push_back(s.substr(i, id - i + 1));
                solve(ans, s, new1, id + 1);
                new1.pop_back();
            }
        }
    }
    vector<vector < string>> partition(string s)
    {
        vector<vector < string>> ans;
        vector<string> v;
        solve(ans, s, v, 0);
        return ans;
    }
};