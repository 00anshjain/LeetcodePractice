class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for(int i = 0; i <= k; i++)
        {
            vector<int> pri(prices.begin(), prices.end());
            for(auto x : flights)
            {
                if(prices[x[0]] != INT_MAX)
                    pri[x[1]] = min(prices[x[0]] + x[2], pri[x[1]]);
            }
            prices = pri;
        }
        if(prices[dst] == INT_MAX)
            return -1;
        return prices[dst];
    }
};