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
        // priority_queue<pair<int, int>> pq;
        deque<int> q;
        q.push_back(0);
        int j = 0;
        for(int i = 1; i < n; i++)
        {
            while(i - q.front() > k)
                q.pop_front();
            int val = nums[q.front()] + nums[i]; 
            // bcse largest value in queue is at front only
            nums[i] = val;
            while(!q.empty() && val > nums[q.back()])
                q.pop_back();
            q.push_back(i);
            // if(i == n-1)
            //     return pq.top().first + nums[i];
            // pq.push({pq.top().first + nums[i], i});
            // // for(int j = i-1; j>= 0 && j >= i-k; j--)
            // {
            //     dp[i] = max(dp[i], dp[j] + nums[i]);
            // }
        }
        return nums[q.back()];
    }
};