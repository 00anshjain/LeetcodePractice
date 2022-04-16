// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int recur(vector<vector<vector<int>>>& dp, int i, int j, int k, string &A, string &B, string &C)
{
    if(i == 0 || j == 0 || k == 0)
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    if(A[i-1] == B[j-1] && B[j-1] == C[k-1])
    {
        return dp[i][j][k] = 1 + recur(dp, i-1, j-1, k-1, A, B, C);
    }
    return dp[i][j][k] = max(max(recur(dp, i-1, j, k, A, B, C), recur(dp, i, j-1, k, A, B, C)), recur(dp, i, j, k-1, A, B, C));
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, -1)));
    return recur(dp, n1, n2, n3, A, B, C);
    
    
    // vector<int, vector<vector<int, vector<int>>> > v;
    // your code here
}