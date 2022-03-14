class Solution {
public:
    typedef long long ll;
    vector<int> singleNumber(vector<int>& nums) {
        ll xorr = 0;
        for(auto x : nums)
            xorr ^= x;
        // for(auto x : nums)
        ll RSB = (xorr & -xorr);
        int num1 = 0, num2 = 0;
        for(auto x : nums)
        {
            if((RSB & x) > 0)
                num1 ^= x;
            else
                num2 ^= x;
        }
        return {num1, num2};
    }
};