class Solution {
public:
    typedef long long ll;
    
    // we get the initial character of string
    // and then we check by putting all 26 characters at front and check if it is a valid conversion
    // dp[i][j] -> represents words starting from i ready to change to initial letter to j
    // we multiply dp[i][j] * dp[j][i] -> 
    //    (no of words ready to convert i to j) * (no of words ready to convert i to j)
    // and we get sum of all these multiplications
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> id(ideas.begin(), ideas.end()); 
        vector<vector<ll>> dp(26, vector<ll>(26, 0));
        for(auto s : id)
        {
            int in = s[0] - 'a';
            string w = s.substr(1);
            for(int i = 0; i < 26; i++)
            {
                char ch = i + 'a';
                // cout<<ch<<endl;
                string g = ch + w;
                if(id.find(g) != id.end())
                    continue;
                dp[in][i]++;
            }
        }
        ll ans = 0;
        for(int i = 0; i < 26; i++)
        {
            for(int j =0; j < 26; j++)
            {
                ans += (dp[i][j] *dp[j][i]);
            }
        }
        return ans;
//         ll ans = 0;
//         unordered_map<string, set<int>> mp;
//         unordered_map<char, set<int>> kmp;
//         // unordered_map<string, vector<bool>(26, false)> mp;
//         vector<int> startLetter(26, 0);
        
//         for(auto s : id)
//         {
//             startLetter[s[0] - 'a']++;
//             // kmp[s[0]-'a']++;
//             mp[s.substr(1)].insert(s[0]-'a');
//         }
        
//         for(auto s : id)
//         {
//             string g = s.substr(1);
//             // ll cnt = 0;
//             for(int i = 0; i < 26; i++)
//             {
//                 if(mp[g].find(i) == mp[g].end())
//                 {
//                     ans += startLetter[i];
//                 }
//             }
//         }
//         return ans;
    }
};