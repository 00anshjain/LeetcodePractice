class Solution {
public:
    int minimumDeletions(string s) {
        int cnt_b = 0;
        for(char c : s)
        {
            if(c == 'b')
                cnt_b++;
        }
        int ans = cnt_b;
        int cnt_a = 0;
        int n = s.size();
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == 'b')
            {
                cnt_b--;
            }
            else
            {
                cnt_a++;
            }
            ans = min(ans, cnt_b + cnt_a);
            
        }
        
        return ans;
        
            
    }
};