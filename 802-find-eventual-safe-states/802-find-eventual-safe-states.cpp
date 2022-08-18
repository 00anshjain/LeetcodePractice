class Solution {
public:
    int DFS(int i, vector<vector<int>> &graph, vector<int> &isSafe)
    {
        if(isSafe[i] != -1)
            return isSafe[i];
        // cout<<i<<endl;
        isSafe[i] = 0;
        for(auto x : graph[i])
        {
            if(DFS(x, graph, isSafe) == 0)
            {
                isSafe[i] = 0;
                return 0;
            }
        }
        isSafe[i] = 1;
        return 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> isSafe(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(isSafe[i] == -1)
                DFS(i, graph, isSafe);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(isSafe[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};