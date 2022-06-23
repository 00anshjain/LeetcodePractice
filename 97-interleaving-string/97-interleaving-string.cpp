class Solution {
public:
    
    bool isInterleave(string A, string B, string C) {
        int i = 0, j = 0, k = 0;
        int n1 = A.size(), n2 = B.size(), n3 = C.size();
        if(n1 + n2 != n3)
            return false;
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n2; i++)
        {
            if(C[i-1] == B[i-1])
                dp[0][i] = true;
            else
                break;
        }
        for(int i = 1; i <= n1; i++)
        {
            if(C[i-1] == A[i-1])
                dp[i][0] = true;
            else
                break;
        }
        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                int k = i+j;
                if(A[i-1] == C[k-1])
                {
                    dp[i][j] =  dp[i][j] || dp[i-1][j];
                }
                if(B[j-1] == C[k-1])
                {
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        return dp[n1][n2];
        
    }
};