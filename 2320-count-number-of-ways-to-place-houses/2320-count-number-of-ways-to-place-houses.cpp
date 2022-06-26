class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    ll recur(vector<ll> &dp, int n)
    {
        // cout<<n<<endl;
        if(n <= 0)
            return 1l;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = (recur(dp, n-2) + recur(dp, n-1))%mod;
    }
    int countHousePlacements(int n) {
        vector<ll> dp(n+1, -1);
        ll a = recur(dp, n);
        return ((ll)a*a)%mod;
    }
};