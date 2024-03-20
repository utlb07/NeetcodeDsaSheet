class Solution {
public:
    int fun(string &s,int i,int j)
    {
        if(i>=j)
        {
            return 1;
        }
        if(s[i]==s[j])
        {
            return fun(s,i+1,j-1);
        }
        return 0;
    }
    int countSubstrings(string s) {
        int ans=0;
        int maxlen=INT_MIN;
        int n=s.length();
        int st=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(fun(s,i,j)==true)
                {
                   ans++;
                }
            }
        }
        return ans;
    }
};