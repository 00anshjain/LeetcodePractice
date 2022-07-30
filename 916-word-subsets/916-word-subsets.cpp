class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> f(26, 0);
        for(auto w : words2)
        {
            vector<int> mp(26, 0);
            for(auto c : w)
            {
                mp[c-'a']++;
            }
            for(int i = 0; i < 26; i++)
            {
                f[i] = max(f[i], mp[i]);
            }
        }
        vector<string> ans;
        for(auto w : words1)
        {
            // unordered_map<char, int> mp;
            vector<int> mp(26, 0);
            for(auto c : w)
                mp[c-'a']++;
            bool flag = false;
            for(int i = 0; i < 26; i++)
            {
                if(mp[i] < f[i])
                {
                    flag = true;
                    break;
                }
            }   
            if(!flag)
                ans.push_back(w);
            
        }
        return ans;
    }
};