class Solution {
public:
    int n, m;
    int xDir[4] = {0, 0, 1, -1};
    int yDir[4] = {1, -1, 0, 0};
    bool isSafe(int x, int y, vector<vector<char>> &board)
    {
        if(x < 0 || y < 0 || x>= n || y >= m || board[x][y] != 'X')
            return false;
        return true;
    }
    void DFS(int i, int j, vector<vector<char>> &board)
    {
        board[i][j] = '.';
        for(int k = 0; k < 4; k++)
        {
            if(isSafe(i + xDir[k], j + yDir[k], board))
                DFS(i + xDir[k], j + yDir[k], board);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'X')
                {
                    DFS(i, j, board);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};