class Solution {
public:
    int minCost(string s, vector<int>& t) {
        int n = s.size();
        if(n <= 1)
            return 0;
        int mx = t[0];
        int cnt = 1;
        int ans = 0;
        int sum = t[0];
        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i-1])
            {
                // cout<<i<<" "<<ans<<endl;
                mx = max(mx, t[i]);
                sum += t[i];
                cnt++;
            }
            else
            {
                cnt = 1;
                ans += (sum - mx);
                // cout<<i<<" "<<ans<<endl;
                // last = s[i];
                sum = t[i];
                mx = t[i];
            }
        }
        if(cnt > 1)
            ans += sum - mx;
        return ans;
    }
};