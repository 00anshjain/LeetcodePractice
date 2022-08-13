class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        // int cnt = n/m + (n%m > 0 ? 1 : 0);
        int cnt = 0;
        int sz = 0;
        string s = "";
        while(sz < m)
        {
            cnt++;
            s += a;
            sz += n;
        }
        int i = 0, j = m-1;
        while(i < sz && s.substr(i, m) != b)
        {
            i++;
        }
        if(i < sz)
            return cnt;
        cnt++;
        s += a;
        sz += n;
        i = 0; j = m-1;
        while(i < sz && s.substr(i, m) != b)
        {
            i++;
        }
        if(i < sz)
            return cnt;
        return -1;
        
    }
};