// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        vector<int> dist(n, INT_MAX);
        dist[S] = 0;
        while(!pq.empty())
        {
            auto p = pq.top();
            int d = p.first;
            int u = p.second;
            pq.pop();
            if(dist[u] < d)
                continue;
            for(auto vec : adj[u])
            {
                int v = vec[0];
                int duv = vec[1];
                if(dist[u] != INT_MAX && dist[v] > d + duv)
                {
                    dist[v] = d + duv;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
        
        // Code here
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends