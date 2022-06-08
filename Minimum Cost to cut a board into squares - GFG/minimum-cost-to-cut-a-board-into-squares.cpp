// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        int xpieces = 1, ypieces = 1;
        sort(X.begin(), X.end(), greater<int>());
        sort(Y.begin(), Y.end(), greater<int>());
        int i = 0, j = 0, cost = 0;
        //hpieces -> no. of piences for horizontal cut
        //hpieces will increase with vertical cut
        // vertical cut-> no of pieces of hpieces will be used, it will increase v cut piece by 1
        M = X.size();
        N = Y.size();
        while(i < M && j < N)
        {
            if(X[i] >= Y[j])
            {
                cost += X[i++]*xpieces;
                ypieces++;
            }
            else
            {
                cost += Y[j++]*ypieces;
                xpieces++;
            }
        }
        while(i<M)
        {
            cost += X[i++]*xpieces;
            ypieces++;
        }
        while(j < N)
        {
            cost += Y[j++]*ypieces;
            xpieces++;
        }
        return cost;
        
        
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends