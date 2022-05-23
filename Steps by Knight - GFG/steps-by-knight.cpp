// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isSafe(int i, int j, int N)
    {
        if(i < 1 || j < 1 || i > N || j > N)
            return false;
        return true;
    }
    int Xarr[8] = {1, 1, -1, -1, 2, -2, 2, -2};
    int Yarr[8] = {2, -2, 2, -2, 1, 1, -1, -1};
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1])
	        return 0;
	    queue<vector<int>> q;
	    vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
	    visited[KnightPos[0]][KnightPos[1]] = true;
	    int chance = 0;
	    q.push(KnightPos);
	    
	    while(!q.empty())
	    {
	        int n = q.size();
	        while(n--)
	        {
    	        auto pos = q.front();
    	        q.pop();
    	        for(int i = 0; i < 8; i++)
    	        {
    	            int X = pos[0] + Xarr[i];
    	            int Y = pos[1] + Yarr[i];
    	            if(isSafe(X, Y, N) && !visited[X][Y])
    	            {
    	                if(X == TargetPos[0] && Y == TargetPos[1])
    	                    return chance + 1;
    	                q.push({X, Y});
    	                visited[X][Y] = true;
    	            }
    	        }
    	       
	        }
	        chance++;
	    }
	    
	    
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends