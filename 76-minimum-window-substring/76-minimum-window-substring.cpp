class Solution {
public:
    string minWindow(string s, string p) {
        unordered_map<char, int> mp;
        // unordered_set<char> st;
        for(auto c : p)
        {
            mp[c]++;
            // st.insert(c);
        }
        int n = s.size();
        int k = p.size();
        if(k > n)
            return "";
        string ans = "";
        int ans_sz = INT_MAX;
        int j = 0;
        int matched = 0;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                mp[s[i]]--;
                if(mp[s[i]]>= 0)
                    matched++;
                while(matched == k)
                {
                    // ans = min(ans, i-j+1);
                    if(i-j+1 < ans_sz)
                    {
                        ans_sz = i-j+1;
                        ans = s.substr(j, i-j+1);
                    }
                    // j++;
                    if(mp.find(s[j]) != mp.end())
                    {
                        mp[s[j]]++;
                        if(mp[s[j]] > 0)
                            matched--;
                    }
                    j++;
                }
            }
        }
        // if(ans == INT_MAX)
        //     return "-1";
        return ans; 
        
    }
};