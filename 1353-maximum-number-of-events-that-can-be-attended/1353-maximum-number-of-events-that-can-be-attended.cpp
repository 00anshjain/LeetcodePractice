class Solution {
public:
    int maxEvents(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int mx = 0;
        int n = arr.size(), ans = 0;
        int idx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, arr[i][1]);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i <= mx; i++)
        {
            while(idx < n && arr[idx][0] == i)
            {
                pq.push(arr[idx++][1]);
            }
            while(!pq.empty() && pq.top() < i)
                pq.pop();
            if(!pq.empty())
            {
                ans++;
                pq.pop();
            }
        }
        return ans;
        
    }
};