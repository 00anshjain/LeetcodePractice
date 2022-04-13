class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int mn = INT_MAX;
        for(auto x : prices)
        {
            if(mn > x)
            {
                mn = x;
            }
            // else
            // {
                int k = x - mn;
                if(pro < k)
                    pro = k;
            // }
        }
        return pro;
    }
};