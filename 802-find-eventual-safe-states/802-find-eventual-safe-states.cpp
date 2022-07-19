class Solution {
public:
    bool DFS(int u, vector<int> &visited, vector<vector<int>>& graph)
    {
        if(visited[u] != -1)
            return visited[u];
        visited[u] = 1;//not safe
        bool flag = false;
        for(auto v : graph[u])
        {
            if(visited[v] == 0)
                continue;
            else if(visited[v] == 1)
            {
                flag = true;//cycle found or unsafe termination found
                continue;
            }
            else
            {
                if(DFS(v, visited, graph)) //true means not terminating
                    flag = true;
            }
        }
        if(!flag) //no problem found good terminating
            visited[u] = 0;//0 means no cycle;
        return visited[u];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            //0 means safe
            // 1 means unsafe
            if(!DFS(i, visited, graph))
                ans.push_back(i);
        }
        return ans;
    }
};