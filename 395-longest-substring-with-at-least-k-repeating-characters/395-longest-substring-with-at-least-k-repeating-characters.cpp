class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_set<char> st(s.begin(), s.end());
        int mxUnique = st.size();
        int n = s.size();
        int ans = 0;
        for(int currUnq = 1; currUnq <= mxUnique; currUnq++)
        {
            unordered_map<char, int> mp;
            int matched = 0, i = 0, unq = 0;
            for(int j = 0; j < n; j++)
            {
                mp[s[j]]++;
                if(mp[s[j]] == 1)
                    unq++;
                if(mp[s[j]] == k)
                {
                    matched++;
                }
                while(unq > currUnq)
                {
                    if(mp[s[i]] == k)
                        matched--;
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        unq--;
                    i++;
                }
                if(matched == unq)
                {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};