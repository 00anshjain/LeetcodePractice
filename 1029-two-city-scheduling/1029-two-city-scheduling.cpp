class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> v; //diff, index
        int n = costs.size();
        for(int i = 0; i < n; i ++)
            v.push_back({costs[i][0] - costs[i][1], i});
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < n/2; i++)
        {
            int k = v[i][1];
            ans += costs[k][0];
        }
        for(int i = n/2 ; i < n; i++)
        {
            int k = v[i][1];
            ans += costs[k][1];
        }
        return ans;
        
        
    }
};