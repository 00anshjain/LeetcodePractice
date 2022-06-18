class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        // int dp[n];
        // vector<int> dp(n, INT_MIN);
        // memset(dp, 0, sizeof(dp));
        // dp[0] = nums[0];
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        int j = 0;
        for(int i = 1; i < n; i++)
        {
            while(i - j > k)
                j++;
            while(!pq.empty() && pq.top().second < j)
                pq.pop();
            if(i == n-1)
                return pq.top().first + nums[i];
            pq.push({pq.top().first + nums[i], i});
            // for(int j = i-1; j>= 0 && j >= i-k; j--)
            // {
            //     dp[i] = max(dp[i], dp[j] + nums[i]);
            // }
        }
        return -1;
    }
};