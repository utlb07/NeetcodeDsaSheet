class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(st.empty()||s[i]=='('||s[i]=='['||s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
               
                // if(st.empty())
                // {
                //     return false;
                // }
                if(s[i]==')'&&st.top()!='('||s[i]==']'&&st.top()!='['||s[i]=='}'&&st.top()!='{')
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};