// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
         sort(intervals.begin(), intervals.end());
         vector<vector<int>> ans;
         int t = -1;
         int j = -1;
         for(int i = 0; i < n; i++)
         {
             if(intervals[i][0] > t)
            {
                j++;
                ans.push_back(intervals[i]);
                t = intervals[i][1];
            }
            else
            {
                ans[j][1] = max(ans[j][1], intervals[i][1]);
                t = ans[j][1];
            }
         }
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends