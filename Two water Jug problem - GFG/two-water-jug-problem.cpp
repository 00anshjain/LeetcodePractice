// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	    pair<int, int> p;
	    bool visited[m+1][n+1];
	    memset(visited, false, sizeof(visited));
	    queue<pair<int, int>> q;
	    q.push({0, 0});
	    if(d > max(n, m))
	        return -1;
	    if(d == 0)
	        return 0;
	    int steps = 0;
	    while(!q.empty())
	    {
	        int sz = q.size();
	        while(sz--)
	        {
    	        auto t = q.front();
    	        q.pop();
    	        int x = t.first;
    	        int y = t.second;
    	        if(x == d || y == d)
    	            return steps;
    	        if(visited[x][y])
    	            continue;
    	        visited[x][y] = true;
    	        if(!visited[x][n])
    	            q.push({x, n});
	            if(!visited[m][y])
    	            q.push({m, y});
    	        int a = min(x, n-y);
    	        if(!visited[x-a][y+a])
    	            q.push({x-a, y+a});
    	        int b = min(m-x, y);
    	        if(!visited[x+b][y-b])
    	            q.push({x+b, y-b});
    	        if(!visited[x][0])
    	            q.push({x, 0});
    	        if(!visited[0][y])
    	            q.push({0, y});
    	        
	        }
	        steps++;
	    }
	    return -1;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends