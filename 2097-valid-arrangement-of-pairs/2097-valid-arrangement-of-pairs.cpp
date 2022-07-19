class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> deg;
        for(auto x : pairs)
        {
            mp[x[0]].push_back(x[1]);
            deg[x[0]]++;
            deg[x[1]]--;
        }
        int start = mp.begin()->first;//in case of complete euler
        for(auto itr = deg.begin(); itr != deg.end(); itr++)
        {
            if((itr->second % 2) == 1)
            {
                start = itr->first;
                break;
            }
        }
        vector<vector<int>> res;
        stack<int> st;
        st.push(start);
        while(!st.empty())
        {
            int u = st.top();
            if(!mp[u].empty())
            {
                int v = mp[u].back();
                mp[u].pop_back();
                st.push(v);
                u = v;
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    reverse(res.begin(), res.end());
                    return res;
                }
                auto v = st.top();
                res.push_back({v, u});
            }
        }
        return res;
    }
};