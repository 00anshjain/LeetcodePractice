class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, long long k) {
        ll sum = 0;
        ll ans = 0;
        ll n = nums.size();
        ll i = 0;
        for(ll j = 0; j < n; j++)
        {
            sum += nums[j];
            while(sum*(j-i+1) >= k)
            {
                sum -= nums[i++];
            }
            if(i <= j)
                ans += (j-i+1);
        }
        return ans;
    }
};