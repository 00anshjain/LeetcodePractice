class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> mp;
        for(auto x : tickets)
            mp[x[0]].insert(x[1]);
        stack<string> st;
        vector<string> res;
        st.push("JFK");
        while(!st.empty())
        {
            string k = st.top();
            if(mp[k].empty())
            {
                res.push_back(k);
                st.pop();
            }
            else
            {
                st.push(*mp[k].begin());
                mp[k].erase(mp[k].begin());
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};