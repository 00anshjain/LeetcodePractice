// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void DFS(int i, vector<int> adj[], stack<int> &st, vector<bool> &visited)
    {
        visited[i] = true;
        for(auto v : adj[i])
        {
            if(!visited[v])
                DFS(v, adj, st, visited);
        }
        st.push(i);
    }
    void DFS2(vector<bool> &visited, int u, vector<int> adj[])
    {
        visited[u] = true;
        for(auto x : adj[u])
        {
            if(!visited[x])
                DFS2(visited, x, adj);
        }
    }
    int kosaraju(int n, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                DFS(i, adj, st, visited);
        }
        vector<int> g[n];
        for(int i = 0; i < n; i++)
        {
            for(auto x : adj[i])
                g[x].push_back(i);
        }
        vector<bool> visited2(n, false);
        int ans = 0;
        while(!st.empty())
        {
            auto t = st.top();
            st.pop();
            if(!visited2[t])
            {
                ans++;
                DFS2(visited2, t, g);
            }
        }
        return ans;
        //code here
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends