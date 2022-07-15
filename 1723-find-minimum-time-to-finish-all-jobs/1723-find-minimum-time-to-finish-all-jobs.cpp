class Solution {
public:
    int n, k;
    int ans = INT_MAX;
    void recur(vector<int> &jobs, int curr, vector<int> &assign, int mx)
    {
        if(mx >= ans)
            return;
        if(curr == 0)
        {
            ans = min(ans, mx);
            return;
        }
        for(int i = 0; i < k; i++)
        {
            if(i > 0 && assign[i] == assign[i-1])
                continue;
            assign[i] += jobs[curr-1];
            int oldmx = mx;
            mx = max(mx, assign[i]);
            recur(jobs, curr-1, assign, mx);
            assign[i] -= jobs[curr-1];
            mx = oldmx;
        }
        
    }
    int minimumTimeRequired(vector<int>& jobs, int K) {
        n = jobs.size();
        k = K;
        ans = 0;
        vector<int> assign(k, 0);
        if(n <= k)
            return *max_element(jobs.begin(), jobs.end());
        sort(jobs.begin(), jobs.end(), greater<int>());
        for(int i = 0; i < n; i += k)
            ans += jobs[i];
        recur(jobs, n, assign, 0);
        return ans;
    }
};