// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int X, Y, n, m;
    int recur(vector<vector<int>> &matrix, int i, int j)
    {
        // if(dp[i][j] != -2)
        //     return dp[i][j];
        if(i == X && j == Y)
            return 0;
        int ans = -1;
        matrix[i][j] = 0;
        if(i+1 < n && matrix[i+1][j] == 1)
        {
            ans = max(ans, recur(matrix, i+1, j));
        }
        if(i-1 >= 0 && matrix[i-1][j] == 1)
        {
            ans = max(ans, recur(matrix, i-1, j));
        }
        if(j+1 < m && matrix[i][j+1] == 1)
        {
            ans = max(ans, recur(matrix, i, j+1));
        }
        if(j-1 >= 0 && matrix[i][j-1] == 1)
        {
            // cout<<"idhar"<<endl;
            ans = max(ans, recur(matrix, i, j-1));
        }
        matrix[i][j] = 1;
        if(ans == -1)
            return -1;
        return ans + 1;
        // dp[i][j] = (ans == -1 ? -1 : ans + 1);
        // return dp[i][j];
        
            
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        n = matrix.size();
        m = matrix[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -2));
        X = xd;
        Y = yd;
        if(matrix[xs][ys] == 0 || matrix[xd][yd] == 0)
            return -1;
        int k = recur(matrix, xs, ys);
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return k;
        // code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends