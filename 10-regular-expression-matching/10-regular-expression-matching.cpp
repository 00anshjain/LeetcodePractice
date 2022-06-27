class Solution {
public:
    //  Read this from discussion => for ".*" => {".", "..", "...", "....", }     
    // ".* " -> "..* " -> ".." -> "a." -> "ab". It matches.
    // The "*" is attached to ".", so, you just make another ".".
    bool recur(string &s, string &p, int i, int j)
    {
        if(i == 0 && j == 0)
            return true;
        if(j == 0)
            return false;
        if(i == 0)
        {
            if(p[j-1] != '*')
                return false;
            return recur(s, p, i, j-2);
        }
        if(s[i-1] == p[j-1] || p[j-1] == '.')
        {
            return recur(s, p, i-1, j-1);
        }
        if(p[j-1] == '*')
        {
            bool k = recur(s, p, i, j-2);
            if(k)
                return k;
            if(p[j-2] == '.')
            {
                // p[j-2] = s[i-1];
                return recur(s, p, i-1, j);
            }
            if(p[j-2] == s[i-1])
                return recur(s, p, i-1, j);
            return false;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return recur(s, p, n, m);
        
    }
};