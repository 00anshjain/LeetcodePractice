class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto &x : s)
            mp[x]++;
        vector<pair<int, char>> v;
        for(auto &x : mp)
            v.push_back({x.second, x.first});
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string ans;
        for(auto &x : v)
        {
            int freq = x.first;
            char c = x.second;
            for(int i = 0; i < freq; i++)
                ans += c;
        }
        return ans;
    }
};