class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            v.push_back({nums[i] + k, i});
            v.push_back({nums[i] - k, i});
        }
        sort(v.begin(), v.end());
        int i = 0;
        vector<int> cnt(n, 0);
        int unq = 0;
        int ans = INT_MAX;
        for(int j = 0; j < 2*n; j++)
        {
            auto t = v[j].second;
            cnt[t]++;
            if(cnt[t] == 1)
                unq++;
            while(unq == n)
            {
                ans = min(ans, v[j].first - v[i].first);
                cnt[v[i].second]--;
                if(cnt[v[i].second] == 0)
                    unq--;
                i++;
            }
        }
        return ans;
    }
};