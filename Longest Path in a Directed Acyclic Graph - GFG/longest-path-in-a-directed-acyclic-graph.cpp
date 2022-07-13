// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    typedef pair<int, int> pii;
    void toposort(int u, stack<int> &st, vector<bool> &visited, vector<pii> adj[])
    {
        visited[u] = true;
        for(auto x : adj[u])
        {
            int v = x.first;
            if(!visited[v])
                toposort(v, st, visited, adj);
        }
        st.push(u);
    }
    vector <int> maximumDistance(vector<vector<int>> edges,int n,int e,int S)
    {
              
        //trying with TopoSort, to get Answer in O(n+e) time 
        // dijkstra takes time nlogn;
        vector<pair<int, int>> adj[n];
        vector<int> inDegree(n, 0);
        for(auto x : edges)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        stack<int> st;
        vector<bool> visited(n, false);
        toposort(S, st, visited, adj);
        vector<int> dist(n, INT_MIN);
        dist[S] = 0;
        while(!st.empty())
        {
            int t = st.top();
            st.pop();
            if(dist[t] == INT_MIN)
                continue;
            for(auto x : adj[t])
            {
                int v = x.first;
                int d = x.second;
                if(dist[v] < dist[t] + d)
                    dist[v] = dist[t] + d;
            }
        }
        return dist;
            // code here
      }
};

// { Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}  // } Driver Code Ends