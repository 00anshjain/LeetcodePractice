class Solution {
public:
    typedef long long ll;
    long long maximumSubsequenceCount(string text, string pattern) {
        char a = pattern[0], b = pattern[1];
        ll ans = 0, cnt_a = 0, cnt_b = 0;
        for(auto c : text)
        {
            if(c == b)
            {
                ans += cnt_a;
                cnt_b++;
            }
            if(c == a)
            {
                cnt_a++;
            }
            
        }
        return ans + max(cnt_a, cnt_b);
    }
};