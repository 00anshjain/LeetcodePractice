class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        // for(int i = 1; i < m; i++)
        // {
        //     if(mat[0][i] != 0)
        //         mat[0][i] += mat[0][i-1];
        //     ans += mat[0][i];
        // }
        // for(int i = 1; i < n; i++)
        // {
        //     if(mat[i][0] != 0)
        //         mat[i][0] += mat[i-1][0];
        //     ans += mat[i][0];
        // }
        // cout<<ans<<endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i != 0)
                if(mat[i][j] != 0) mat[i][j] += mat[i-1][j];
                int k = j;
                int smallest = mat[i][k];
                while(k >= 0 && mat[i][k] > 0)
                {
                    smallest = min(smallest, mat[i][k]);
                    ans += smallest;
                    k--;
                }
            }
        }
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //         cout<<mat[i][j]<<" ";
        //     cout<<endl;
        // }
        return ans;
        
    }
};