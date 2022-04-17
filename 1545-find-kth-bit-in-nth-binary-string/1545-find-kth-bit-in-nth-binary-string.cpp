class Solution {
public:
    void makeNewString(string &s)
    {
        // string k = s;
        s += '1';
        for(int i = s.size() - 2; i>= 0; i--)
        {
            if(s[i]== '1')
                s += '0';
            else
                s += '1';
        }
        // return k;
    }
    char recur(string &s, int k, int n)
    {
        if(s.size() >= k)
            return s[k-1];
        // s = 
            makeNewString(s);
        return recur(s, k, n);
    }
    char findKthBit(int n, int k) {
        if(k == 1)
            return '0';
        string s = "0";
        return recur(s, k, n);
    }
};