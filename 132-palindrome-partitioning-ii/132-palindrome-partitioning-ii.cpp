class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int cut[n];
        for(int i = 0; i < n; i++)
            cut[i] = i;
        //to find out how many cut needed for string of size i 
        vector<vector<bool>> dp(n, (vector<bool>(n, false)));
        for(int j = 0; j < n; j++)  // string start se end tak h,  end = j
        {
            for(int i = j; i >= 0; i--)     // start changing;
            {
                if(s[i] == s[j] && ((j - i + 1 <= 2) || dp[i+1][j-1]))
                {
                    dp[i][j] = true;
                    if(i != 0)
                        cut[j] = min(cut[j], cut[i-1] + 1);
                    else
                        cut[j] = 0;
                        // i = 0 mtlb starting se yaha tak aaye koi cut nhi lagana pada
                }
            }
        }
        return cut[n-1];
    }
};