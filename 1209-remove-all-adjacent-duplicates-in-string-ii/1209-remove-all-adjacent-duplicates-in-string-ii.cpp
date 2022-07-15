class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(auto c : s)
        {
            if(st.empty())
                st.push({c, 1});
            else if(st.top().first != c)
            {
                st.push({c, 1});
            }
            else if(st.top().second != k-1)
            {
                st.push({c, st.top().second + 1});
            }
            else
            {
                for(int i = 0; i < k-1; i++)
                    st.pop();
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};