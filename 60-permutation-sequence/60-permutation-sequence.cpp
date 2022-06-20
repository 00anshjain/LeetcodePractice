class Solution {
public:
    int K;
    string ans;
    void recur(string s, int sz, int n, vector<bool>& taken, string &curr)
    {
        if(K == 0)
            return;
        if(sz == n)
        {
            K--;
            if(K== 0)
                ans = curr;
            return;
                
        }
        for(int j = 0; j < n; j++)
        {
            if(!taken[j])
            {
                taken[j] = true;
                curr += s[j];
                recur(s, sz+1, n, taken, curr);
                curr.pop_back();
                taken[j] = false;
            }
        }
    }
    string getPermutation(int n, int k) {
        string s= "";
        for(int i = 1; i <= n; i++)
            s+= to_string(i);
        K = k;
        vector<bool> taken(n, false);
        if(k == 1)
            return s;
        string curr = "";
        ans = "";
        recur(s, 0, n, taken, curr);
        return ans;
    }
};