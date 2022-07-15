class Solution {
public:
    int ans = INT_MAX;
    int n;
    int taken[1<<15][16];
    int recur(vector<int>& tasks, int &sessionTime, int currSessTime, int mask)
    {
        if(mask == ((1<<n) - 1))
        {
            // cout<<"here"<<endl;
            //ans = min(ans, s);
            return 1;
        }
        if(taken[mask][currSessTime] != -1)
            return taken[mask][currSessTime];
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(tasks[i] != -1)
            {
                int k = tasks[i];
                tasks[i] = -1;
                if(currSessTime + k <= sessionTime)
                {
                    ans = min(ans, recur(tasks, sessionTime, currSessTime + k, mask | (1<<i)));
                }
                else
                {
                    
                    int z = recur(tasks, sessionTime, k, mask | (1<<i));
                    if(z != INT_MAX)
                        ans = min(ans, 1+z);
                }
                tasks[i] = k;
            }
        }
        return taken[mask][currSessTime] = ans;
        
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size();
        int mask = 0;
        memset(taken, -1, sizeof(taken));
        // vector<vector<bool>> taken(1<<n, vector<bool>(tasks.size() + 1, false));//maxm session = n
        ans = INT_MAX;
        return recur(tasks, sessionTime, 0, mask);
        // return ans;
    }
};