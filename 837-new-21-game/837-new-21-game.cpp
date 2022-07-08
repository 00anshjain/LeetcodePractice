class Solution {
public:
    double new21Game(int n, int k, int maxPoints) {
        if(n < k)
            return 0;
        int end = k + maxPoints;
        if(n >= end)
            return 1;
        if(k == 0)
            return 1;
        vector<double> dp(n+1);
        double percnt = 1.0;
        dp[0] = 1.0;
        int i;
        for(int i = 1; i <= maxPoints && i < k; i++)
        {
            dp[i] = (1.0/maxPoints)*percnt;
            percnt += dp[i];
        }
        // int j = 0;
        int j = min(0, k-maxPoints-1);
        for(int i = maxPoints+1; i < k; i++)
        {
            percnt -= dp[j];
            j++;
            dp[i] = (1.0/maxPoints)*percnt;
            percnt += dp[i];
        }
        double ans = 0;
        if(n == k  && k == 0)
            return 1;
        for(int i = k; i <= n; i++)
        {
            if(j >= 0)
                percnt -= dp[j];
            j++;
            dp[i] =  (1.0/maxPoints)*percnt;
            ans += dp[i];
        }
        return ans;

    }
};