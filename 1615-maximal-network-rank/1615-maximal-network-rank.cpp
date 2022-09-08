class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // vector<vector<int>> r(n, vector<int>(n, 0));
        //removed this because Each pair of cities has at most one road connecting them.
        vector<int> total(n, 0); //total number of roads from one vertex
        unordered_set<int> st; 
        //we will make a number from vertices and add it to set
        //doing this so that we can use unorderedSet
        for(auto x : roads)
        {
            // r[x[0]][x[1]]++;
            // r[x[1]][x[0]]++;
            total[x[0]]++;
            total[x[1]]++;
            st.insert((min(x[0], x[1])<<16) + max(x[0], x[1]));
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                // if(i == j)
                //     continue;
               ans = max(ans, total[i] + total[j] - (int)st.count((i<<16) + j)); 
            }
        }
        // for(auto x : roads)
        // {
        //     ans = max(ans, total[x[0]] + total[x[1]] - r[x[0]][x[1]]);
        // }
        return ans;
    }
};