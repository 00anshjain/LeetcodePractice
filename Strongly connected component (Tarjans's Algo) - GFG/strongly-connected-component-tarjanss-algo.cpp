// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    int t = 0;
    void DFS(int u, vector<int> &dis, vector<int> &low, stack<int> &st, vector<bool> &inStack, vector<int> adj[], vector<vector<int>>& ans)
    {
        dis[u] = t++;
        low[u] = dis[u];
        st.push(u);
        inStack[u] = true;
        for(auto v : adj[u])
        {
            if(dis[v] == -1)
            {
                DFS(v, dis, low, st, inStack, adj, ans);
                low[u] = min(low[u], low[v]);
            }
            else if(inStack[v])
            {
                low[u] = min(low[u], dis[v]);
            }
        }
        if(low[u] == dis[u])
        {
            vector<int> v;
            while(st.top() != u)
            {
                v.push_back(st.top());
                inStack[st.top()] = false;
                st.pop();
            }
            v.push_back(st.top());
            inStack[st.top()] = false;
            st.pop();
            sort(v.begin(), v.end());
            ans.push_back(v);
        }
        // inStack[u] = false;
        // st.pop();
    }
    vector<vector<int>> tarjans(int n, vector<int> adj[])
    {
        vector<int> dis(n, -1); //discoveryTime
        vector<int> low(n, -1); //lowTime
        t = 0;
        vector<vector<int>> ans;
        stack<int> st;
        vector<bool> inStack(n, false);
        for(int i = 0; i < n; i++)
        {
            if(dis[i] == -1)
            {
                DFS(i, dis, low, st, inStack, adj, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        // int stronglyConnected = 0;
        // for(int i = 0; i < n; i++)
        // {
        //     if(low[i] == dis[i])
        //     {
        //         stronglyConnected++;
        //     }
        // }
        // return stronglyConnected;
        
        
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends