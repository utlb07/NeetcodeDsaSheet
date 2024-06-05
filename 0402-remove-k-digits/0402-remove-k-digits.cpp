class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<int>st;
        string ans;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()>num[i]-'0' && k>0)
            {
                st.pop();
                k--;
            }
            if(!st.empty() || num[i]!='0')
            {
                st.push(num[i]-'0');
            }
        }
        while(!st.empty()&&k>0)
        {
            st.pop();
            k--;
        }
        if(st.empty())
        {
            return "0";
        }
        while(!st.empty())
        {
            ans+=st.top()+'0';
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};
