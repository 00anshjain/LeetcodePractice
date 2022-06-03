class Solution {
public:
    static bool comp(pair<string, int> p1, pair<string, int> p2)
    {
        if(p1.second == p2.second)
        {
            return p1.first < p2.first; 
        }
        return p1.second > p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto x : words)
            mp[x]++;
        vector<pair<string, int>> v;
        for(auto x : mp)
            v.push_back({x.first, x.second});
        sort(v.begin(), v.end(), comp);
        vector<string> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};