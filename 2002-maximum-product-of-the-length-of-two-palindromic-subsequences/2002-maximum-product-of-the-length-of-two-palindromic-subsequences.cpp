class Solution {
public:
    int n, ans;
    bool isPalin(string &s)
    {
        int k = s.size();
        if(k <= 1)
            return true;
        int i = 0;
        k--;
        while(i < k)
        {
            if(s[i] != s[k])
                return false;
            k--;
            i++;
        }
        return true;
        
    }
    void recur(int i, string& s1, string& s2, string &s)
    {
        if(i == n)
        {
            if(isPalin(s1) && isPalin(s2))
            {
                // cout<<s1<<" "<<s2<<endl;
                
                ans = max(ans, (int)(s1.size()*s2.size()));
            }
            return;
        }
        recur(i+1, s1, s2, s);
        s1.push_back(s[i]);
        recur(i+1, s1, s2, s);
        s1.pop_back();
        s2.push_back(s[i]);
        recur(i+1, s1, s2, s);
        s2.pop_back();
        
        
    }
    int maxProduct(string s) {
        ans = 0;
        n = s.size();
        string s1 = "", s2 = "";
        recur(0, s1, s2, s);
        return ans;
    }
};