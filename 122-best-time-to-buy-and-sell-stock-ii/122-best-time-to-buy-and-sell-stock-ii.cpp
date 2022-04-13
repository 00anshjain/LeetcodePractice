class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int buy = -1;
        int n = prices.size();
        int i = 0;
        while(i < n)
        {
            if(buy == -1)
            {
                while(i + 1 < n && prices[i+1] <= prices[i])
                    i++;
                // cout<<"BUY"<<i<<endl;
                if(i < n-1)
                    buy = prices[i];
            }
            else
            {
                while(i + 1 < n && prices[i+1] >= prices[i])
                // {
                    i++;
                // }
                // cout<<"SELL"<<i<<endl;
                if(i < n)
                {
                    pro += (prices[i] - buy);
                    buy = -1;
                }
            }
            i++;
        }
        return pro;
        
    }
};