class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        ll ans = 0;
        sort(nums.begin(), nums.end());
        vector<ll> pow2(nums.size()+1, 1);
        for(int i = 1; i < nums.size(); i++)
        {
            pow2[i] = (2*pow2[i-1])%mod;
        }
        while(i <= j)
        {
            ll sum = nums[i] + nums[j];
            if(sum <= target)
            {
                ll k = pow2[j-i];
                k %= mod;
                ans += k;
                ans %= mod;
                i++;
            }
            else
                j--;
        }
        return ans;
    }
};