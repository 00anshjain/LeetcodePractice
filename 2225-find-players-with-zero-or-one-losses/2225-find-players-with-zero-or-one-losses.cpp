class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        vector<vector<int>> res(2);
//         res[0].clear();
//         res[1].clear();
        
        // 0 won, 1 lose, -1 out
        for(auto x : matches)
        {
            int p1 = x[0];
            int p2 = x[1];
            if(mp.find(p1) == mp.end())
            {
                mp[p1] = 0;//win
            }
            if(mp.find(p2) == mp.end())
            {
                mp[p2] = 1; //lose
            }
            else if(mp[p2] == 0)
                mp[p2] = 1;
            else if(mp[p2] == 1)
                mp[p2] = -1;
            
        }
        for(auto x : mp)
        {
            if(x.second == 0)
                res[0].push_back(x.first);
            else if(x.second == 1)
            {
                // cout<<x.first<<" "<<x.second<<endl;
                res[1].push_back(x.first);
            }
        }
        // for(auto itr = mp.begin(); itr != mp.end(); itr++)
        // {
        //     cout<<itr->first<<" "<<itr->second<<endl;
        //     if(itr->second == 1)
        //         res[1].push_back(itr->first);
        //     else if(itr->second == 0)
        //         res[0].push_back(itr->first);
        //     // else
        //     //     continue;
        // }
        sort(res[1].begin(), res[1].end());
        sort(res[0].begin(), res[0].end());
            
        return res;
    }
};