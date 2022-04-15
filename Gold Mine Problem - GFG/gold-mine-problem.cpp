// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //         cout<<M[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int j = m-2; j >= 0; j--)
        {
            for(int i = 0; i < n ; i++)
            {
                int k = 0;
                if(i > 0)
                    k = max(k,M[i-1][j+1]);
                    k = max(k,M[i][j+1]);
                if(i < n-1)
                
                    k = max(k,M[i+1][j+1]);
                M[i][j] += k;
            }
        }
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //         cout<<M[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, M[i][0]);
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends