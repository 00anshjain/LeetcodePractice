class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        vector<pair<int, int>> g;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(img2[i][j])
                    g.push_back({i, j});
            }
        }
        for(int vshift = -n+1; vshift <= n-1; vshift++)
        {
            for(int hshift = -n+1; hshift <= n-1; hshift++)
            {
                vector<vector<int>> img(n, vector<int>(n, 0));
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(hshift + i > n-1 || hshift + i < 0)
                            continue;
                        if(vshift + j > n-1 || vshift + j < 0)
                            continue;
                        img[i+hshift][j+vshift] = img1[i][j];
                    }
                }
                int cnt = 0;
                for(auto x : g)
                {
                    if(img[x.first][x.second])  cnt++;
                }
                // for(int i = 0; i < n; i++)
                // {
                //     for(int j = 0; j < n; j++)
                //     {
                //         if(img[i][j] ==1 && img2[i][j] == 1)
                //             cnt++;
                //     }
                // }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};