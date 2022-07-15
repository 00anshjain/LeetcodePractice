class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(i > 0)
            {
                for(int j = 0; j < m; j++)
                {
                    if(mat[i][j])
                        mat[i][j] += mat[i-1][j];
                }
            }
            vector<int> v(mat[i].begin(), mat[i].end());
            sort(v.begin(), v.end(), greater<int>());
            int h = INT_MAX;
            for(int i =0; i < m; i++)
            {
                h = min(h, v[i]);
                if(h == 0)
                    continue;
                ans = max(ans, h*(i+1));
            }
   
        }
        return ans;
    }
};