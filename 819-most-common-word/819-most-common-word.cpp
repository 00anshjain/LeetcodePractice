class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        unordered_map<string, int> mp;
        unordered_set<string> st(banned.begin(), banned.end());
        int n = para.size();
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            
            if(!isalpha(para[i]))
            {
                if(i == j)
                {
                    j++;
                    continue;
                }
                // if(j-i > 1)
                mp[para.substr(j, i-j)]++;
                j = i+1;
            }
            para[i] = tolower(para[i]);
        }
        if(j != n)
        {
            mp[para.substr(j, n-j)]++;
        }
        vector<pair<int, string>> v;
        for(auto x : mp)
        {
            v.push_back({x.second, x.first});
            // cout<<x.second<<" "<<x.first<<endl;
        }
        sort(v.begin(), v.end());
        // for(auto x : v)
        // {
        //     // v.push_back({x.second, x.first});
        //     cout<<x.second<<" "<<x.first<<endl;
        // }
        
        int k = v.size();
        for(int i = k-1; i>= 0; i--)
        {
            if(st.find(v[i].second) == st.end())
                return v[i].second;
        }
        return "-1";
    }
};