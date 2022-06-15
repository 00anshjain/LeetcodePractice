class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> mp;
        for(char c : s)
            mp[c]++;
        bool flag = false;
        int ans = 0;
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if((itr->second)%2 == 0)
            {
                ans += itr->second;
            }
            else
            {
                ans += (itr->second) - 1;
                flag = true;
            }
        }
        if(flag)
            return ans + 1;
        return ans;
        
    }
};