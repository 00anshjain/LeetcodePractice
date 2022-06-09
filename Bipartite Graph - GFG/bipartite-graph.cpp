// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool getColored(int u, vector<int>& color, vector<int> adj[], int col)
    {
        color[u] = col;
        for(auto x : adj[u])
        {
            if(color[x] != -1)
            {
                if(color[x] == col)
                    return false;
            }
            else
            {
                if(!getColored(x, color, adj, 1 - col))
                    return false;
            }
        }
        return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> color(n, -1);
	    for(int i = 0; i < n; i++)
	    {
	        if(color[i] == -1)
	        {
    	        if(!getColored(i, color, adj, 0))
    	            return false;
	        }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends