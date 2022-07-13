// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution {
public:
    bool DFS(vector<pair<int, int>> adj[], int u, int k, vector<bool> &visited)
    {
        visited[u] = true;
        if(k <= 0)
            return true;
        for(auto x : adj[u])
        {
            int v = x.first;
            int d = x.second;
            if(!visited[v])
            {
                if(DFS(adj, v, k-d, visited))
                    return true;
            }
        }
        visited[u] = false;
        return false;
    }
    bool pathMoreThanK(int n, int E, int k, int *a) 
    { 
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < 3*E; i+=3)
        {
            adj[a[i]].push_back({a[i+1], a[i+2]});
            adj[a[i+1]].push_back({a[i], a[i+2]});
            
        }
        vector<bool> visited(n, false);
        return DFS(adj, 0, k, visited);
       //  Code Here
    } 
};




// { Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends