class Solution {
public:
    int n;
    int getD(vector<vector<int>> &board, int d)
    {
        // int r = ((n*n) - i) / n;
        int totalRows = n;
        int r, c;
        int k;
        
        r = (n-1) - (d-1)/n;
        // for(int i = 1; i <= n; i++)
        // {
        //     if(n*i >= d)
        //     {
        //         r = n-i;
        //         k = i-1;
        //         break;
        //     }
        // }
        
        c = ((d-1)%n);
        if(r%2 == n%2)
            c = n-1 - c;
//         if(k % 2 == 0)
//         {
           
//         }
//         else
//         {
//             c = (n-1) - ((d-1)%n);
//         }
        if(board[r][c] == -1)
            return d;
        return board[r][c];
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        
        vector<bool> visited(401, false);
        queue<int> q;
        q.push(1);
        n = board.size();
        // if(n == 1)
        //     return 0;
        int turn = 0;
        visited[1] = true;
        while(!q.empty())
        {
            int sz = q.size();
            turn++;
            while(sz--)
            {
                int t = q.front();
                q.pop();

                for(int i = 1; i <= 6; i++)
                {
                    int d = t + i;
                    if(d > n*n)
                        break;
                    if(visited[d])
                        continue;
                    visited[d] = true;
                    d = getD(board, d);
                    // visited[d] = true;
                    if(d == n*n)
                        return turn;
                    q.push(d);   
                }
            }
        }
        return -1;
    }
};