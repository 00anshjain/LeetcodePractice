class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[n-1][m-1])
            return false;
        int row = n-1;
        int col = 0;
        while(row >= 0 && col < m)
        {
            if(target < matrix[row][col])
                row--;
            else if(target > matrix[row][col])
                col++;
            else
                return true;
        }
        return false;
    }
};