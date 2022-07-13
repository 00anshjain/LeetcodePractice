class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n);
        for(int i = 0; i < n; i++)
            cut[i] = i;
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        for(int j = 0; j < n; j++)//fixing the ending position
        {
            for(int i = j; i >= 0; i--)//changing starting position
            {
                if(s[i] == s[j] && ((j-i+1) <= 2 || palin[i+1][j-1]))
                {
                    palin[i][j] = true;
                    if(i != 0)
                        cut[j] = min(cut[j], 1 + cut[i-1]);
                    else
                        cut[j] = 0;
                }
            }
        }
        return cut[n-1];
        
        // vector<int> dp(n, -1);
        // return recur(s, 0, dp, palin)-1;
    }
};