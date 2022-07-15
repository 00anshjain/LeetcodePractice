// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
int total_cost(vector<vector<int>>cost){
    int n = cost.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; //node, mask
    int mask = 0;
    int maxMask = (1<<n)-1;
    pq.push({0, 0, 1});//distane, vertex, inital mask = 1<<0 => 1
    vector<vector<bool>> visited(n, vector<bool>(1<<n, false));
    int ans = INT_MAX;
    while(!pq.empty())
    {
        vector<int> t = pq.top();
        pq.pop();
        int u = t[1];
        int d = t[0];
        int m = t[2];
        if(visited[u][m])
            continue;
        visited[u][m] = true;
        // cout<<u<<" "<<" "<<m<<" "<<d<<"  d[u][0]="<<cost[u][0]<<"  ";
        if(m == (1<<n) - 1)
        {
            ans = min(ans, d + cost[u][0]);
            continue;
        }
        // if(u == 0 && m == ((1<<n) - 1))
        // {
        //     // cout<<u<<" "<<m<<" "<<d<<" selected"<<endl;
        //     return d;
        // }
        for(int i = 0; i < n; i++)
        {
            if(m & 1<<i)
                continue;
            if(!visited[i][m|(1<<i)])
            // {
                // cout<<"from"<<u<<" to"<<i<<" mask"<<m<<" "<<(m|1<<i)<<" "<<d<<"+"<<cost[u][i]<<endl;
                // cout<<"jump="<<cost[u][i]<<endl;
                pq.push({cost[u][i]+d, i, m | (1<<i)});
            // }
        }
    }
    return ans;
    // Code here
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends