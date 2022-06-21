class Solution {
public:
    struct Job{
        int start;
        int end;
        int profit;
        Job(int a, int b, int c)
        {
            start = a;
            end = b;
            profit = c;
        }
    };
    static bool comp(Job &j1, Job &j2)
    {
        return j1.start < j2.start;
    }
        
    int recur(int t, int i, int n, vector<Job>& j, vector<int>& dp)
    {
        if(i == n)
            return 0;
        if(j[i].start < t)
            return recur(t, i+1, n, j, dp);
        if(dp[i] != -1)
            return dp[i];
        if(j[i].start >= t)
        {
            return dp[i] = max(recur(j[i].end, i+1, n, j, dp) + j[i].profit, recur(t, i+1, n, j, dp));
        }
        return 0;
        // return dp[i] = recur(t, i+1, n, j, dp);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> j;
        for(int i = 0; i < n; i++)
        {
            // Job *p = new Job(startTime[i], endTime[i], profit[i]);
            j.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(j.begin(), j.end(), comp);
        vector<int> dp(n+1, -1);
        int ans = 0;
        for(int i = n-1; i>= 0; i--)
            ans = max(ans, recur(j[i].start, i, n, j, dp));
        return ans;
    }
};