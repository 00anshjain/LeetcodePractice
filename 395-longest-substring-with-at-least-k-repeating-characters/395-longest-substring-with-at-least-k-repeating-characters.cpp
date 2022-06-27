class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_set<char> st(s.begin(), s.end());
        int mxUnq = st.size();
        int ans = 0;
        int n = s.size();
        for(int currUnq = 0; currUnq <= mxUnq; currUnq++)
        {
            int unq = 0;
            unordered_map<char, int> mp;
            int i = 0;
            int matched = 0;
            for(int j = 0; j < n; j++)
            {
                mp[s[j]]++;
                if(mp[s[j]] == 1)
                    unq++;
                if(mp[s[j]] == k)
                    matched++;
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
                    ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};