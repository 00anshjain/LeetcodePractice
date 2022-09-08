class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while(k-- > 0)
        {
            auto t = pq.top();
            pq.pop();
            t++;
            pq.push(t);
        }
        long long ans = 1l;
        int mod = 1e9+7;
        if(pq.top() == 0)
            return 0;
        while(!pq.empty())
        {
            ans *= pq.top();
            ans %= mod;
            pq.pop();
        }
        return ans;
    }
};