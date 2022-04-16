class Solution {
public:
    int isPalin(int i, int j, string &s, int n)
    {
        int cnt = 0;
        while(i >= 0 && j < n && (s[i--] == s[j++]))
        {
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cnt += isPalin(i, i, s, n);
            cnt += isPalin(i, i+1, s, n);
        }
        return cnt;
    }
};