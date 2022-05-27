class Solution {
public:
    int maxUnq(string &s)
    {
        vector<bool> taken(26, false);
        int mx = 0;
        for(auto c : s)
        {
            if(!taken[c-'a'])
            {
                mx++;
                taken[c-'a'] = true;
            }
        }
        return mx;
    }
    int longestSubstring(string s, int k) {
        int maxUnique = maxUnq(s); 
        int ans = 0, n = s.size();
        for(int currUnq = 1; currUnq <= maxUnique; currUnq++)
        {
            int j = 0, i = 0, unq = 0, kGreater = 0;
            unordered_map<char, int> mp;
            while(j < n)
            {
                mp[s[j]]++;
                if(mp[s[j]] == 1)
                {
                    unq++;
                }
                if(mp[s[j]] == k)
                    kGreater++;
                while(unq > currUnq)
                {
                    
                    if(mp[s[i]] == k)
                        kGreater--;
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        unq--;
                    i++;
                    
                }
                if(kGreater == unq)
                {
                    ans = max(ans, j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};