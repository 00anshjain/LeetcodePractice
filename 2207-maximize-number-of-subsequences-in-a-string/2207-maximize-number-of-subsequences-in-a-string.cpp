class Solution {
public:
    typedef long long ll;
    long long maximumSubsequenceCount(string text, string pattern) {
        ll res = 0, cnt1 = 0, cnt2 = 0;
        for (auto & c: text) {   
            if (c == pattern[1]){
                res += cnt1;
                cnt2++;
            }
            if (c == pattern[0])
                cnt1++;
        }
        return res + max(cnt1, cnt2);
        
        
    }
};