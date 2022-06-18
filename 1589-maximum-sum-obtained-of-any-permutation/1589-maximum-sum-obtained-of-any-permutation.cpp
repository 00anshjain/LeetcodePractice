class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        // unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> req(n+1, 0);
        for(auto x : requests)
        {
            int start = x[0];
            int end = x[1];
            req[start]++;
            req[end+1]--;
            // int i = start;
            // while(i <= end)
            // {
            //     mp[i]++;
            //     i++;
            // }
        }
        for(int i = 1; i < n; i++)
            req[i] = req[i-1] + req[i];
        sort(req.begin(), req.end(), greater<int>());
        // priority_queue<pair<int, int>> pq;
        // for(int i = 0; i < n; i++)
        //     pq.push({req[i], i});
        sort(nums.begin(), nums.end(), greater<int>());
        int i = 0;
        ll sum = 0;
        while(i < n && req[i] > 0)
        {
           // sum += ((ll)nums[i]*pq.top().first)%mod;
           //  pq.pop();
            sum += ((ll)nums[i]*req[i])%mod;
            i++;
            sum%= mod;
        }
        return (int)sum;
    }
};