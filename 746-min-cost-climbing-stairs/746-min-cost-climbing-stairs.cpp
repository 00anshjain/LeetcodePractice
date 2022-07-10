class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n < 2)
            return 0;
        int mn = cost[0];
        int mn1 = cost[1];
        for(int i = 2; i < n; i++)
        {
            int h = min(mn1 + cost[i], mn + cost[i]);
            mn = mn1;
            mn1 = h;
        }
        return min(mn, mn1);
    }
};