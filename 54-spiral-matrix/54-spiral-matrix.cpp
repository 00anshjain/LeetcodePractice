class Solution {
public:
    void helper(vector<vector<int>>& mat, int r, int c, int n, int m, vector<int>& ans)
    {
        if(r >= n || c >= m)
            return;
        for(int j = c; j < m; j++)
            ans.push_back(mat[r][j]);
        for(int i = r+1; i < n; i++)
            ans.push_back(mat[i][m-1]);
        if((n-1) != r)
        {
            for(int j = m-2; j >= c; j--)
                ans.push_back(mat[n-1][j]);
        }
        if((m-1) != c)
        {
            for(int i = n-2; i > r; i--)
                ans.push_back(mat[i][c]);
        }
        helper(mat, r+1, c+1, n-1, m-1, ans);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        helper(matrix, 0, 0, n, m, ans);
        return ans;
    }
};