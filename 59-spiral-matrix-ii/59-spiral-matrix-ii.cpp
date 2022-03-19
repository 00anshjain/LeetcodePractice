class Solution {
public:
    int num = 0;
    void helper(vector<vector<int>>& mat, int r, int c, int n)
    {
        if(r >= n || c >= n)
            return;
        for(int j = c; j < n; j++)
            mat[r][j] = num++;
        for(int i = r+1; i < n; i++)
            mat[i][n-1] = num++;
        if((n-1) != r)
        {
            for(int j = n-2; j >= c; j--)
                mat[n-1][j] = num++;
        }
        if((n-1) != c)
        {
            for(int i = n-2; i > r; i--)
                mat[i][c] = num++;
        }
        helper(mat, r+1, c+1, n-1);
    }
    vector<vector<int>> generateMatrix(int n) {
        num = 1;
        vector<vector<int>> mat(n, vector<int>(n));
        helper(mat, 0, 0, n);
        return mat;
        
        // helper(mat)
    }
};