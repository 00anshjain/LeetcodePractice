class Solution {
public:
    int m, n;
    int dir[4][2]= {{-1, 0},
                    {0, 1},
                    {0, -1},
                    {1, 0}};
    bool isSafe(int r, int c, vector<vector<char>> &board)
    {
        if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] == '&')
            return false;
        return true;
    }
    bool recur(vector<vector<char>> &board, string &word, int l, int r, int c)
    {
        if(l == 0)
            return true;
        char cr = board[r][c];
        board[r][c] = '&';
        for(int i = 0; i < 4; i++)
        {
            int R = r + dir[i][0];
            int C = c + dir[i][1];
            if(isSafe(R, C, board) && board[R][C] == word[l-1])
            {
                if(recur(board, word, l-1, R, C))
                    return true;
            }
        }
        board[r][c] = cr;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int l = word.size();
        m = board.size();
        n = board[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[l-1])
                {
                    board[i][j] = '&';
                    if(recur(board, word, l-1, i, j))
                        return true;
                    board[i][j] = word[l-1];
                }
            }
            
        }
        return false;
        
    }
};