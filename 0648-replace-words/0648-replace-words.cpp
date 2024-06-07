class Solution
{
    public:
        string replaceWords(vector<string> &dict, string sentence)
        {
            unordered_set<string> st;
            for (auto it: dict)
            {
                st.insert(it);
            }
            string ans="", curr="";
            bool found = false;
            for (char character: sentence)
            {
                if (character != ' ')
                {
                    curr += character;
                    if (!found && st.count(curr))
                    {
                        ans += curr;
                        found = true;
                    }
                }
                else
                {
                    if (!found)
                    {
                        ans += curr;
                    }
                    ans += ' ';
                    curr = "";
                    found = false;
                }
            }
            if (!found)
            {
                ans += curr;
            }
            return ans;
        }
};