class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int total = 0, mx = 0;
        int ans = 0, j = 0, n = s.size();
        for(int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            total++;
            if(mp[s[i]] > mx)
            {
                mx = mp[s[i]]; 
            }
            int Kreq = total - mx;
            while(Kreq > k)
            {
                mp[s[j]]--;
                j++;
                total = 0;
                mx = 0;
                for(auto x : mp)
                {
                    total += x.second;
                    mx = max(mx, x.second);
                }
                Kreq = total - mx;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};