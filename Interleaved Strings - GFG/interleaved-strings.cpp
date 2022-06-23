// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    // bool recur(int i, int j, int k, vector<vector<int>> &dp, string &A, string &B, string &C)
    // {
    //     if(k == 0)
    //         return true;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     bool ans1 = false, ans2 = false;
    //     if(i != 0)
    //     {
    //         if(A[i-1] == C[k-1])
    //             ans1 = recur(i-1, j, k-1, dp, A, B, C);
    //         if(ans1)
    //             return dp[i][j] = 1;
    //     }
    //     if(j != 0)
    //     {
    //         if(B[j-1] == C[k-1])
    //             ans2 = recur(i, j-1, k-1, dp, A, B, C);
    //         if(ans2)
    //             return dp[i][j] = 1;
    //     }
    //     return dp[i][j] = 0;
    // }
    bool isInterleave(string A, string B, string C) 
    {
        int i = 0, j = 0, k = 0;
        int n1 = A.size(), n2 = B.size(), n3 = C.size();
        if(n1 + n2 != n3)
            return false;
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n2; i++)
        {
            if(C[i-1] == B[i-1])
                dp[0][i] = true;
            else
                break;
        }
        for(int i = 1; i <= n1; i++)
        {
            if(C[i-1] == A[i-1])
                dp[i][0] = true;
            else
                break;
        }
        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                int k = i+j;
                if(A[i-1] == C[k-1])
                {
                    dp[i][j] =  dp[i][j] || dp[i-1][j];
                }
                if(B[j-1] == C[k-1])
                {
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        return dp[n1][n2];
        // return recur(n1, n2, n3, dp, A, B, C);
        // while(i < n1 && j < n2)
        // {
        //     if(C[k] == A[i])
        //         i++;
        //     else if(C[k] == B[j])
        //         j++;
        //     else
        //         return false;
        //     k++;
        // }
        // while(i < n1)
        // {
        //     if(C[k] == A[i])
        //         i++;
        //     else
        //         return false;
        //     k++;
        // }
        // while(j < n2)
        // {
        //     if(C[k] == B[j])
        //         j++;
        //     else
        //         return false;
        //     k++;
        // }
        // return true;
        //Your code here
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends