// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void DFS1(int u, stack<int> &st, vector<int> adj[], vector<bool>& visited)
    {
        visited[u] = true;
        for(auto x : adj[u])
        {
            if(!visited[x])
                DFS1(x, st, adj, visited);
        }
        st.push(u);
    }
    void DFS2(int u, vector<bool> &visited, vector<int> adj[])
    {
        visited[u] = true;
        for(auto x : adj[u])
        {
            if(!visited[x])
                DFS2(x, visited, adj);
        }
    }
    int kosaraju(int n, vector<int> adj[])
    {
        stack<int> st1;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                DFS1(i, st1, adj, visited);
        }
        // so we have got stack1
        // now we reverse edges to check strongly connected components
        vector<int> g[n];
        for(int i = 0; i < n; i++)
        {
            for(auto x : adj[i])
            {
                g[x].push_back(i);
            }
        }
        int stronglyConnected = 0;
        vector<bool> visited2(n, false);
        while(!st1.empty())
        {
            if(!visited2[st1.top()])
            {
                stronglyConnected++;
                DFS2(st1.top(), visited2, g);
            }
            st1.pop();
        }
        return stronglyConnected;
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