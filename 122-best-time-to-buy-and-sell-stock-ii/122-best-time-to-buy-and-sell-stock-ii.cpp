class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int i = 0;
        while(i < n)
        {
            
            if(i+1 < n && prices[i+1] > prices[i])
            {
                // while(j+1 < n && prices[j+1] > prices[j])
                //     j++;
                profit += (prices[i+1] - prices[i]);
                // i = j + 1;
            }
            // else
                i++;
            
            
            
            // int j = i;
            // if(j+1 < n && prices[j+1] > prices[j])
            // {
            //     // while(j+1 < n && prices[j+1] > prices[j])
            //     //     j++;
            //     profit += (prices[j] - prices[i]);
            //     i = j + 1;
            // }
            // else
            //     i++;
        }
        return profit;
    }
};