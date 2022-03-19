// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    void helper(vector<vector<int>>& mat, int r, int c, int n, int m, vector<int>& ans)
    {
        if(r >= n || c >= m)
            return;
        for(int j = c; j < m; j++)
            ans.push_back(mat[r][j]);
        for(int i = r+1; i < n; i++)
            ans.push_back(mat[i][m-1]);
        if((n-1) != r)
        {
            for(int j = m-2; j >= c; j--)
                ans.push_back(mat[n-1][j]);
        }
        if((m-1) != c)
        {
            for(int i = n-2; i > r; i--)
                ans.push_back(mat[i][c]);
        }
        helper(mat, r+1, c+1, n-1, m-1, ans);
    }
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int n, int m) 
    {
        // int n = matrix.size();
        // int m = matrix[0].size();
        vector<int> ans;
        helper(matrix, 0, 0, n, m, ans);
        return ans;

        // code here 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends