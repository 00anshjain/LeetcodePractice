class Solution {
public:
    int maxConsecutive(int btm, int top, vector<int>& s) {
        // int btm = bottom - 1;
        // int curr = bpottom - 1;
        // int top = top + 1;
        s.push_back(btm - 1);
        s.push_back(top+1);
        sort(s.begin(), s.end());
        int n = s.size(), ans = 0;
        for(int i = 1; i < n; i++)
            ans = max(ans, s[i] - s[i-1]-1);
        return ans;
    }
};