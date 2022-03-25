// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101], int m, int color[], int size, int index)
{
    // issafe edge hai ya nahi or hai to unka color same hai ki nahi
    for(int i = 0; i < index; i++)
    {
        if(graph[i][index] == 1 &&  color[i] == color[index])
            return false;
    }
    return true;
}


bool fnc(bool graph[101][101], int m, int size, int index, int color[])
{
    // base case jab index = size to it means ki vo waha tak phouch sakta haasdfi
    if(index == size)
        return true;
        
    for(int i = 1; i <= m; i++)
    {
        color[index] = i;
        
        if(isSafe(graph, m, color, size, index))
        {
            if(fnc(graph, m, size, index+1, color))
                return true;
        }
            
    }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int v)
{
    // your code here
    int color[v];
    memset(color, 0, sizeof(color));
    return fnc(graph, m, v, 0, color);
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