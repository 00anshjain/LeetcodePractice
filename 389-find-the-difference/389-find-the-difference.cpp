class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_map<char, int> mp;
        // for(char x : s)
        //     mp[x]++;
        // for(auto x : t)
        // {
        //     if(mp[x] == 0)
        //         return x;
        //     else
        //         mp[x]--;
        // }
        // return 'a';
        int xorr = 0;
        for(int x : s)
            xorr ^= x;
        for(int x : t)
            xorr ^= x;
        return (char)xorr;
        
    }
};