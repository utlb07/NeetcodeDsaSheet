class Solution
{
    public:
        int fun(unsigned int n)
        {
            int count = 0;
            while (n)
            {
                count += n &1;
                n >>= 1;
            }
            return count;
        }
    vector<int> sortByBits(vector<int> &arr)
    {
        map<int, int>mp;
        for(int i = 0; i < arr.size(); i++){
            int SetBits =fun(arr[i]);
            mp[arr[i]] = SetBits;
        }   
        sort(arr.begin(), arr.end(),[&](int a , int b){
            if(mp[a] == mp[b])
                return a < b;
            return mp[a] < mp[b];
        });
        return arr;
    }
};