class Solution {
public:
    typedef long long ll;
    int findIntegers(int n) {
        // int mxmBit = ceil(log2(n));
        // cout<<mxmBit<<endl;
        // ll dp[mxmBit+1];   // we get numbers with no continuous one number of bits i 
        int dp[32];
        dp[0] = 1;
        dp[1] = 2;
        // for(int i = 2; i <= mxmBit; i++)
        for(int i = 2; i < 32; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        int ans = 0;
        int k = 30, pre_bit = 0;
        while(k >= 0)
        {
            if(n & (1<<k))
            {
                ans += dp[k];
                if(pre_bit)   // if two continuous one, then return
                    return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            k--;
        }
        return ans+1; // to consider givennumber also, as if it reaches here means no two continuous one
        // //now using kernighams algo we jump on set bits
        // while(n > 0)
        // {
        //     int rbsm = n & -n;
        //     int k = log2(rbsm);
        //     cout<<k<<endl;
        //     if(k != 0)
        //         ans += dp[k];
        //     n = n - rbsm;
        // }
        // return ans;
        
        
        
    }
};