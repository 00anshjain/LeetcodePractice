class TreeAncestor {
public:
    vector<vector<int>> adj;
    int timer = 0;
    unordered_map<int, vector<int>> levelOrder;
    unordered_map<int, int> nodeLevel, inTime, outTime;
    void DFS(vector<vector<int>> &adj, int root, int level)
    {
        nodeLevel[root] = level;
        // cout<<root<<endl;
        levelOrder[level].push_back(root);
        inTime[root] = timer++;
        for(auto x : adj[root])
        {
            DFS(adj, x, level+1);
        }
        outTime[root] = timer++;
    }
    TreeAncestor(int n, vector<int>& parent) {
        // vector<>
        adj.resize(n+1);
        int root = 0;
        for(int i = 0; i < n; i++)
        {
            if(parent[i] != -1)
                adj[parent[i]].push_back(i);
            else//if(parent[i] ==)
                root = i;
        }
        timer = 0;
        DFS(adj, root, 0);
        // cout<<"DFS"<<endl;
    }
    
    int getKthAncestor(int node, int k) {
        int l = nodeLevel[node];
        // cout<<"node="<<node<<" l="<<l<<" k="<<k<<" ";
        if(l-k < 0)
            return -1;
        // cout<<l-k<<endl;
        int in = inTime[node];
        int out = outTime[node];
        for(auto x : levelOrder[l-k])
        {
            if(inTime[x] < in && outTime[x] > out)
                return x;
        }
        return -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */