class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        unordered_map<string, int> mp;
        for(auto x : words)
            mp[x]++;
        for(auto z : mp)
        {
            string x = z.first;
            int n = s.size();
            int m = x.size();
            while(n > 0 && m > 0)
            {
                if(m > n)
                    break;
                if(s[n-1] == x[m-1])
                    m--;
                n--;
            }
            if(m == 0)
                cnt+= z.second;
        }
        return cnt;
    }
};