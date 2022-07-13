// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector <int> maximumDistance(vector<vector<int>> edges,int n,int e,int S)
    {
              
        vector<pair<int, int>> adj[n];
        for(auto x : edges)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, S});
        vector<int> dist(n, INT_MIN);
        dist[S] = 0;
        while(!pq.empty())
        {
            auto p = pq.top();
            int d = p.first;
            int u = p.second;
            pq.pop();
            if(dist[u] > d)
                continue;
            for(pair<int, int> p : adj[u])
            {
                int v = p.first;
                int duv = p.second;
                if(dist[u] != INT_MIN && dist[v] < d + duv)
                {
                    dist[v] = d + duv;
                    pq.push({dist[v], v});
                }
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