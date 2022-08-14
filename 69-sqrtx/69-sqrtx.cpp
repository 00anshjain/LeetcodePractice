class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int ans = -1;
        while(l <= r)
        {
            long long mid = ((long long)l+r)/2;
            if((mid*mid) <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};