class Solution {
public:
    typedef vector<int> vi;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto x : flights)
            adj[x[0]].push_back({x[1], x[2]});
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        vector<int> start = {0, src, k+1};
        pq.push(start);
        vector<vector<bool>> visited(n, vector<bool>(k+2, false));
        while(!pq.empty())
        {
            vector<int> v = pq.top();
            pq.pop();
            if(visited[v[1]][v[2]])
                continue;
            visited[v[1]][v[2]] = true;
            // cout<<v[1]<<" "<<v[0]<<" "<<v[2]<<endl;
            if(v[1] == dst)
                return v[0];
            if(v[2] == 0)
                continue;
            for(auto x : adj[v[1]])
            {
                int newPt = x.first;
                int newd = x.second;
                pq.push({v[0] + newd, newPt, v[2] - 1});
            }
        }
        return -1;
    }
};