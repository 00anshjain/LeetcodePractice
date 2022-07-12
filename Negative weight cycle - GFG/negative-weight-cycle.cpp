// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, INT_MAX);
	    dist[0] = 0;
	    for(int t = 0; t < n; t++)
	    {
	        bool flag = false;
	        for(auto x : edges)
	        {
	            if(dist[x[0]] != INT_MAX && dist[x[1]] > dist[x[0]] + x[2])
	            {
	                flag = true;
	                dist[x[1]] = dist[x[0]] + x[2];
	               // cout<<x[1]<<" "<<x[0]<<
	            }
	        }
	        if(!flag)
	            return false;
	        
	    }
	    return true;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends