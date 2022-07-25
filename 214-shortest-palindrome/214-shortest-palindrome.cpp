class Solution {
public:
    string shortestPalindrome(string s) {
        string g(s);
        int n = s.size();
        reverse(g.begin(), g.end());
        string v = s + '#' + g;
        int sz = v.size();
        vector<int> pi(sz, 0);
        // int j = 0;
        for(int i = 1; i < sz; i++)
        {
            int j = pi[i-1];
            while(j > 0 && v[i] != v[j])
                j = pi[j-1];
            if(v[i] == v[j])
                j++;
            pi[i] = j;  
        }
        return g.substr(0, n-pi[sz-1]) + s;
    }
};