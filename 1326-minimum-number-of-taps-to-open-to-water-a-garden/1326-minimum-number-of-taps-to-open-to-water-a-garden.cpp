class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jump(n+1, 0);
        for(int i =0; i <= n; i++)
        {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            jump[l] = max(jump[l], r-l);
        }
        int mx = 0;
        int curr = 1;
        int jmp = 0;
        for(int i = 0; i <= n; i++)
        {
            if(i > mx)
                return -1;
            mx = max(mx, i + jump[i]);
            curr--;
            if(curr == 0)
            {
                curr = mx-i;
                jmp++;
            }
        }
        return jmp-1;
    }
};