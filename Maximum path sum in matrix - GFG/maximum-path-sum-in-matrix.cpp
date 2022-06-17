// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        if(n == 1)
            return mat[0][0];
        for(int i = 1; i <n; i++)
        {
            mat[i][0] += max(mat[i-1][0], mat[i-1][1]);
            
            for(int j = 1; j < n-1; j++)
            {
                mat[i][j] += max(max(mat[i-1][j-1], mat[i-1][j]), mat[i-1][j+1]);
            }
            mat[i][n-1] += max(mat[i-1][n-1], mat[i-1][n-2]);
            
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, mat[n-1][i]);
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends