class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto c : t)
            mp[c]++;
        int n = s.size();
        int len = INT_MAX;
        int start = -1;
        // int start = 0, end = INT_MAX-2;
        unordered_map<char, int> cmp;
        int k = mp.size();
        int unq = 0;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            int c = s[i];
            if(mp.find(c) == mp.end())
            {
                cmp[c]++;
                // continue;
            }
            else
            {
                cmp[c]++;
                if(cmp[c] == mp[c])
                    unq++;
                while(unq == k)
                {
                    if(len > i-j+1)
                    {
                        len = i-j+1;
                        start = j;
                    }
                    if(cmp[s[j]] == mp[s[j]])
                        unq--;
                    cmp[s[j]]--;
                    j++;
                }
            }
        }
        if(start == -1)
            return "";
        return s.substr(start, len);
    }
};