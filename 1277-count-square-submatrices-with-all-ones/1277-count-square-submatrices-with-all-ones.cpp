class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0)
                {
                    if(mat[i][j] == 1)
                        ans++;
                    continue;
                }
                if(mat[i][j] == 1)
                {
                    mat[i][j] = 1 + min({mat[i-1][j], mat[i][j-1], mat[i-1][j-1]});
                    ans += mat[i][j];
                }
            }
        }
        return ans;
    }
};