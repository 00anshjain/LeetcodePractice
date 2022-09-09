class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> mp;
        for(auto& s : cpdomains)
        {
            int n = s.size(), i = 0;
            while(s[i] != ' ')
            {
                i++;
            }
            int freq = stoi(s.substr(0, i));
            string g = s.substr(i+1);
            int k = i;
            // mp[g] += freq;
            while(i < n)
            {
                if((i == k || s[i] == '.') && i + 1 < n && s[i+1] != '.')
                {
                    mp[s.substr(i+1)] += freq;
                }
                i++;
            }
        }
        vector<pair<int, string>> v;
        for(auto x : mp)
        {
            v.push_back({x.second, to_string(x.second) + " " + x.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, string>>());
        vector<string> res;
        for(auto x : v)
            res.push_back(x.second);
        return res;
    }
    
};