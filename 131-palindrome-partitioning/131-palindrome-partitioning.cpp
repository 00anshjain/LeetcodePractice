class Solution {
public:
    int n;
    bool isPalin(string &s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void recur(string &s, int i, vector<vector<string>>& res, vector<string> &cur)
    {
        if(i == n)
        {
            res.push_back(cur);
            return;
        }
        for(int j = i; j < n; j++)
        {
            if(isPalin(s, i, j))
            {
                cur.push_back(s.substr(i, j-i+1));
                recur(s, j+1, res, cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int i = 0;
        n = s.size();
        vector<vector<string>> res;
        vector<string> cur;
        recur(s, i, res, cur);
        return res;
    }
};