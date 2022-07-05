class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++)
        {
            pq.push({rat[i], i});
        }
        vector<int> arr(n, 0);
        int ans = 0;
        while(!pq.empty())
        {
            auto [rating, i] = pq.top();
            pq.pop();
            int cdy = 1;
            if(i-1 >= 0  && rat[i-1] < rat[i])
            {
                cdy = max(cdy, arr[i-1] + 1);
            }
            if(i+1 < n  && rat[i+1] < rat[i])
            {
                cdy = max(cdy, arr[i+1] + 1);
            }
            arr[i] = cdy;
            ans += cdy;
        }
        return ans;
    }
};