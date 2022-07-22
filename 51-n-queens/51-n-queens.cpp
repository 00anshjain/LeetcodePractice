class Solution {
public:
    int N;
    bool isSafe(int row, int col, vector<string> &board)
    {
        for(int i = 0; i < row; i++)
        {
            if(board[i][col] == 'Q')
                return false;
        }
        int i = row - 1, j = col- 1;
        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i--;j--;
        }
        i = row - 1; j = col + 1;
        while(i >= 0 && j < N)
        {
            if(board[i][j] == 'Q')
                return false;
            i--;j++;
        }
        return true;
    }
    void recur(int row, vector<string>& board, vector<vector<string>>& res)
    {
        if(row == N)
        {
            res.push_back(board);
            return;
        }
        for(int i = 0; i < N; i++)
        {
            if(isSafe(row, i, board))
            {
                board[row][i] = 'Q';
                recur(row+1, board, res);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>>res;
        recur(0, board, res);
        return res;
    }
};