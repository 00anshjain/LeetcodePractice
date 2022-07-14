class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, stack<int>> mp;
        unordered_map<int, int> deg;
        
        for(auto x : pairs)
        {
            mp[x[0]].push(x[1]);
            deg[x[0]]++;
            deg[x[1]]--;
        }
        int start = (mp.begin())->first;//start vertex, complete eulerian
        for(auto x : mp)
        {
            // if(out[x.first] - in[x.first] == 1)
            if(deg[x.first] == 1)
            {
                start = x.first;
                break;
            }
        }
        int u = start;
        int end = -1;
        vector<vector<int>> res;
        stack<int> st;
        st.push(start);
        while(!st.empty())
        {
            int u = st.top();
            if(!mp[u].empty())
            {
                int v = mp[u].top();
                mp[u].pop();
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