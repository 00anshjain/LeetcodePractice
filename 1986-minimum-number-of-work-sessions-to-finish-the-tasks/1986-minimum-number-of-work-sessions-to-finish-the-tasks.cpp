class Solution {
public:
    int n;
    bool ok(vector<int> &tasks, int st, int curr, vector<int> &assign, int m)
    {
        if(curr == 0)
            return true;
        for(int i = 0; i < m; i++)
        {
            if(assign[i] + tasks[curr - 1] <= st)
            {
                assign[i] += tasks[curr - 1];
                if(ok(tasks, st, curr-1, assign, m))
                    return true;
                assign[i] -= tasks[curr - 1];
            }
            if(assign[i] == 0)
                break;
        }
        return false;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size();
        int l = 1, r = n;
        int ans = -1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            vector<int> assign(mid, 0);
            if(ok(tasks, sessionTime, n, assign, mid))
            {
                ans = mid;
                r = mid -1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};