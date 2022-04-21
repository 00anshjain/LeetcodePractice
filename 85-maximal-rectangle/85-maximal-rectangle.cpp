class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i <n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                dp[i][j] = j == 0 ? 1 : 1 + dp[i][j-1];
                int i1 = i;
                int smallest = dp[i1][j];
                while(i1>= 0 && matrix[i][j] == '1')
                {
                    smallest = min(smallest, dp[i1][j]);
                    ans = max(ans, smallest * (i-i1+1));
                    i1--;
                }
            }
        }
        return ans;
    }
};