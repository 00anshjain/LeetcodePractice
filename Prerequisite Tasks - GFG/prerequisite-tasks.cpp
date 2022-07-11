// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& pre) {
	    vector<int> adj[n];
	   // for(auto p : pre)
	   //     adj[p.second].push_back(p.first);
	    vector<int> inDegree(n, 0);
	    int c = 0;
	    
	   // memset(inDegree, 0, sizeof(inDegree));
	    for(auto x : pre)
	    {
	        adj[x.second].push_back(x.first);
	       // if(x.first == x.second)
	       //     return false;
	        inDegree[x.first]++;
	    }
	    queue<int> q;
	    for(int i = 0; i< n; i++)
	    {
	        if(inDegree[i] == 0)
	        {
	            q.push(i);
	           c++;
	        }
	    }
	    while(!q.empty())
	    {
	        int t = q.front();
	        q.pop();
	        for(auto x : adj[t])
           {
               inDegree[x]--;
               if(inDegree[x] == 0)
                {
                    c++;
                    q.push(x);
                }
           }
	    }
	    return c == n;
	   // for(int i = 0; i < n; i++)
	   // {
	   //    // cout<<inDegree[i]<<" ";
	   //     if(inDegree[i] > 0)
	   //         return false;
	   // }
	   // return true;
	   // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends