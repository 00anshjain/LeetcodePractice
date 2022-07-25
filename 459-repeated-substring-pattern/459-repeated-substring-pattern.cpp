class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> pi(n, 0);
        for(int i = 1; i < n; i++)
        {
            int j = pi[i-1];
            while(j > 0 && s[i] != s[j])
                j = pi[j-1];
            if(s[i] == s[j])
                j++;
            pi[i] = j;
        }
        // cout<<pi[n-1]<<endl;
        if(pi[n-1] == 0)
            return false;
        return (n % (n - pi[n-1]) == 0);
    }
};