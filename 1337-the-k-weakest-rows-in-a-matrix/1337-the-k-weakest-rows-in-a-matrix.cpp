class Solution {
public:
    static bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        if(p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first < p2.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> v;
        for(int i = 0; i < m; i ++)
        {
            int count = 0;
            int j;
            for(j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                    break;
            }
            v.push_back({j, i});
            
        }
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        for(int i = 0; i < k; i ++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};