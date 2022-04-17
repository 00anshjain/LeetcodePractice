class Solution {
public:
    string makeNewString(string s)
    {
        string k = s;
        k += '1';
        for(int i = s.size() - 1; i>= 0; i--)
        {
            if(s[i]== '1')
                k += '0';
            else
                k += '1';
        }
        return k;
    }
    char recur(string &s, int k, int n)
    {
        if(s.size() >= k)
            return s[k-1];
        s = makeNewString(s);
        return recur(s, k, n);
    }
    char findKthBit(int n, int k) {
        if(k == 1)
            return '0';
        string s = "0";
        return recur(s, k, n);
    }
};