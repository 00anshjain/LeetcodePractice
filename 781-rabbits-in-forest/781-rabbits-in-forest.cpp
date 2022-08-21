class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // unordered_map<int, int> mp;
        unordered_set<int> st;
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto x : answers)
        {
            if(x == 0)
            {
                ans++;
                continue;
            }
            // mp[x]++;
            if(mp[x] % (x+1) == 0)
            {
                ans += (x+1);
            }
            mp[x]++;
            // else if(st.find(x) == st.end())
            // {
            //     st.insert(x);
            //     mp[x]++;
            //     ans += x+1;
            // }
            // else if()
        }
        return ans;
    }
};