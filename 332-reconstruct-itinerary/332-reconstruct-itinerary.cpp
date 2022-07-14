class Solution {
public:
    // typedef tup;
    vector<string> ans;
    bool flag = false;
    void recur(vector<string> &path, string curr, int totalFlights, map<string, map<string, int>>& adj)
    {
        if(flag)
            return;
        path.push_back(curr);
        if(totalFlights == 0)
        {
            ans = path;
            flag = true;
            return;
        }
        auto p = adj[curr];
        {
            for(auto x : p)
            {
                string v = x.first;
                int cnt = x.second;
                if(cnt > 0)
                {
                    adj[curr][v]--;
                    recur(path, v, totalFlights-1, adj);
                    if(flag)
                        return;
                    adj[curr][v]++;
                }
            }
        }
        path.pop_back();
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int totalFlights = tickets.size();
        map<string, map<string, int>> adj;
        flag = false;
        for(auto x : tickets)
        {
            adj[x[0]][x[1]]++;
        }
        
        vector<string> path;
        string curr = "JFK";
        recur(path, curr, totalFlights, adj);
        return ans;
    }
};