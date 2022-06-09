// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int u, int c, bool graph[101][101], vector<int>& color, int n)
{
    for(int i = 0; i < n; i++)
    {
        // if(i == u)
        //     continue;
        if(graph[u][i] && color[i] == c)
            return false;
    }
    return true;
}
bool getColored(int u, bool graph[101][101], int m, int n, vector<int>& color)
{
    if(u == n)
        return true;
    for(int i = 0; i < m; i++)
    {
        if(isSafe(u, i, graph, color, n))
        {
            color[u] = i;
            if(getColored(u+1, graph, m, n, color))
                return true;
        }
    }
    color[u] = -1;
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, -1);
    // for(int i = 1; i <= n; i++)
    // {
        // if(color[i] == -1)
        // {
            // if(!getColored(i, graph, m, n, color))
            //     return false;
        // }
    // }
    return getColored(0, graph, m, n, color);
    // return true;
    // your code here
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends