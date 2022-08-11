class Solution {
public:
    string shortestPalindrome(string v) {
        string g(v);
        int sz = v.size();
        reverse(g.begin(), g.end());
        string s = v + "#" + g;
        int n = s.size();
        // for(int i = 0; i < n; i++)
        vector<int> pi(n, 0);
        for(int i = 1; i < n; i++)
        {
            int j = pi[i-1];
            while(j > 0 && s[j] != s[i])
                j = pi[j-1];
            if(s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return g.substr(0, sz - pi[n-1]) + v;
        
    }
};