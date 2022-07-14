class Solution {
public:
    // typedef tup;
    vector<string> ans;
    bool flag = false;
    void recur(vector<string> &path, string curr, int totalFlights, set<string>& all, map<pair<string, string>, int>& mp)
    {
        if(flag)
            return;
        path.push_back(curr);
        if(totalFlights == 0)
        {
            // if(ans.size() == 0)
                ans = path;
                flag = true;
                return;
            // else
            // {
            //     int sz = path.size();
            //     // cout<<path.size()<<endl;
            //     for(int i = 0; i < sz; i++)
            //     {
            //         // cout<<path[i]<<" "<<ans[i]<<endl;
            //         if(path[i] < ans[i])
            //         {
            //             // cout<<" changed"<<endl;
            //             ans = path;
            //             break;
            //         }
            //         else if(path[i] > ans[i])
            //             break;
            //     }
            // }
            path.pop_back();
            return;
        }
        for(auto x: all)
        {
            if(mp[{curr, x}] > 0)
            {
                mp[{curr, x}]--;
                recur(path, x, totalFlights-1, all, mp);
                if(flag)
                    return;
                mp[{curr, x}]++;
            }
        }
        path.pop_back();
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int totalFlights = tickets.size();
        set<string> allVertices;
        map<pair<string, string>, int> mp;
        flag = false;
        for(auto x : tickets)
        {
            allVertices.insert(x[0]);
            allVertices.insert(x[1]);
            mp[make_pair(x[0], x[1])]++;
        }
        
        vector<string> path;
        string curr = "JFK";
        recur(path, curr, totalFlights, allVertices, mp);
        return ans;
    }
};