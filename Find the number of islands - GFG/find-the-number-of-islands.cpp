// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int xDir[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    int yDir[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    void DFS(vector<vector<char>> &grid, int i, int j, int n, int m)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1')
        {
            return;
        }
        grid[i][j] = '2';
        for(int k = 0; k < 8; k++)
        {
            DFS(grid, i +xDir[k], j +yDir[k], n, m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    DFS(grid, i, j, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
        // Code here
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends