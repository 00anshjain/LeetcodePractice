class Solution {
public:
    int n;
    void DFS(int u, vector<vector<int>> &con, vector<bool>& visited)
    {
        visited[u] = true;
        for(int i = 0; i < n; i++)
        {
            if(con[u-1][i] && !visited[i+1])
                DFS(i+1, con, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& con) {
        n = con.size();
        int ans = 0;
        vector<bool> visited(n+1, false);
        for(int i = 1; i <=n; i++)
        {
            if(!visited[i])
            {
                ans++;
                DFS(i, con, visited);
            }
        }
        return ans;
    }
};