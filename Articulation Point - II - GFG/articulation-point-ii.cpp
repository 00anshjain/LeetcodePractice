// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int t = 0;
    void DFS(int u, int parent, vector<int> &dis, vector<int> &low, vector<int> adj[], vector<bool> &isArti)
    {
        dis[u] = low[u] = t++;
        int child = 0;
        for(auto v : adj[u])
        {
            if(v == parent)
                continue;
            if(dis[v] == -1)
            {
                DFS(v, u, dis, low, adj, isArti);
                low[u] = min(low[u], low[v]);
                if(low[v] >= dis[u] && parent != -1)
                {
                    isArti[u] = true;
                }
                child++;
            }
            else
            {
                low[u] = min(low[u], dis[v]);
            }
        }
        if(parent == -1 && child > 1)
        {
            isArti[u] = true;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> dis(n, -1);
        vector<int> low(n, -1);
        vector<bool> isArti(n, false);
        // vector<bool>
        t = 0;
        for(int i = 0; i < n; i++)
        {
            if(dis[i] == -1)
            {
                DFS(i, -1, dis, low, adj, isArti);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(isArti[i])
                ans.push_back(i);
        }
        if(ans.size() == 0)
            return {-1};
        return ans;
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends