class Solution {
public:
    int ans = INT_MAX;
    int n;
    int taken[1<<15][15][16];
    void recur(vector<int>& tasks, int left, int &sessionTime, int s, int currSessTime, int mask)
    {
        if(taken[mask][s][currSessTime])
            return;
        if(s >= ans)
            return;
        if(left == 0)
        {
            //ans = min(ans, s);
            ans = s;
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(tasks[i] != -1)
            {
                int k = tasks[i];
                tasks[i] = -1;
                if(currSessTime + k <= sessionTime)
                {
                    recur(tasks, left-1, sessionTime, s, currSessTime + k, mask | (1<<i));
                }
                recur(tasks, left-1, sessionTime, s+1, k, mask | (1<<i));
                tasks[i] = k;
            }
        }
        taken[mask][s][currSessTime] = true;
        
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size();
        int mask = 0;
        memset(taken, false, sizeof(taken));
        // vector<vector<bool>> taken(1<<n, vector<bool>(tasks.size() + 1, false));//maxm session = n
        ans = INT_MAX;
        recur(tasks, n, sessionTime, 1, 0, mask);
        return ans;
    }
};