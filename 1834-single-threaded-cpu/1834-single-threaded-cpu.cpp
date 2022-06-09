class Solution {
public:
    typedef long long ll;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = tasks.size();
        for(int i = 0; i < n; i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        ll t = 0;
        int i = 0;
        vector<int> ans;
        while(!pq.empty() || i < n)
        {
            if(pq.empty())
            {
                // ans.push_back(i);
                // t = tasks[i][0] + tasks[i][1];
                t = tasks[i][0];
                // i++;
            }
            else
            {
                auto p = pq.top();
                pq.pop();
                t += p.first;
                ans.push_back(p.second);
            }
            while(i < n && tasks[i][0] <= t)
            {
                // cout<<t<<" "<<tasks[i][0]<<" "<<tasks[i][1]<<" "<<i<<endl;
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
        }
        return ans;
    }
};