class Solution {
public:
    vector<int> prefix_function(string &s)
    {
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
        return pi;
    }
    int strStr(string t, string s) {
        // int i = 0;
        vector<int> pi = prefix_function(s);
        int pos = -1;
        int i(0), j(0);//trying this way of initialization
        while(i < t.size())
        {
            if(t[i] == s[j])
            {
                j++;
                i++;
            }
            else{
                if(j != 0)
                {
                    j = pi[j-1];
                }
                else
                    i++;
            }
            if(j == s.size())
                return i-s.size();
        }
        return -1;
    }
};