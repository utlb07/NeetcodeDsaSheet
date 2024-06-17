class Solution
{
    public:
        bool judgeSquareSum(int c) {
             long long l = 0, r = sqrt(c);
        while(l <= r) {
            if(l * l + r * r == c) return true;
            if(l * l + r * r > c) r--;
            else l++;
        }
        return false;
        }
};