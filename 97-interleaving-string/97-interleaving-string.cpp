class Solution {
public:
    bool recur(int i, int j, int k, vector<vector<int>> &dp, string &A, string &B, string &C)
    {
        if(k == 0)
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        bool ans1 = false, ans2 = false;
        if(i != 0)
        {
            if(A[i-1] == C[k-1])
                ans1 = recur(i-1, j, k-1, dp, A, B, C);
            if(ans1)
                return dp[i][j] = 1;
        }
        if(j != 0)
        {
            if(B[j-1] == C[k-1])
                ans2 = recur(i, j-1, k-1, dp, A, B, C);
            if(ans2)
                return dp[i][j] = 1;
        }
        return dp[i][j] = 0;
    }
    bool isInterleave(string A, string B, string C) {
        int i = 0, j = 0, k = 0;
        int n1 = A.size(), n2 = B.size(), n3 = C.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        if(n1 + n2 != n3)
            return false;
        return recur(n1, n2, n3, dp, A, B, C);
        while(i < n1 && j < n2)
        {
            if(C[k] == A[i])
                i++;
            else if(C[k] == B[j])
                j++;
            else
                return false;
            k++;
        }
        while(i < n1)
        {
            if(C[k] == A[i])
                i++;
            else
                return false;
            k++;
        }
        while(j < n2)
        {
            if(C[k] == B[j])
                j++;
            else
                return false;
            k++;
        }
        return true;
        
    }
};