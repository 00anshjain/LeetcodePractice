class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, vector<int>> mp;
        int n = votes[0].size();
        for(int i = 0; i < n; i++)
        {
            for(auto x : votes)
            {
                mp[x[i]].push_back(i);
            }
        }
        vector<pair<vector<int>, char>> v;
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            v.push_back({itr->second, itr->first});
        }
        sort(v.begin(), v.end());
        string ans = "";
        for(auto x : v)
            ans += x.second;
        return ans;
    }
};