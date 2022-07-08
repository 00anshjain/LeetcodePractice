class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        if(n >= k + maxPts)
            return 1;
        if(k == 0)
            return 1;
        double dp[n+1];
        dp[0] = 0.0;
        // dp[0] = 1.0;
        double sum = 0.0;
        double res = 0.0;
        for(int i = 1; i <= n; i++)
        {
            // if(i < k)
            dp[i] = i <= maxPts ? ((1.0/maxPts)*sum + (1.0/maxPts)) : ((1.0/maxPts)*sum);
            
            if(i < k)
                sum += dp[i];
            if(i > maxPts)
                sum -= dp[i-maxPts];
            if(i >= k)
                res += dp[i];
        }
        return res;
    }
};