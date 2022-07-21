class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int l = -1;
        // if(n == 0)
        //     return {newInterval};
        vector<vector<int>> inter;
        int j = 0;
        // if(n > 0 && newInterval[1] < intervals[0][0])
        // {
        //     inter.push_back(newInterval);
        //     l = newInterval[1];
        // }
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            auto x = intervals[i];
            l = intervals[i][1];
            if(x[1] < newInterval[0] || x[0] > newInterval[1])
            {
                if(x[0] > newInterval[1] && !flag)
                {
                    inter.push_back(newInterval);
                    flag = true;
                }
                inter.push_back(x);
                j++;
                continue;
            }
            else
            {
                inter.push_back(newInterval);
                inter[j][0] = min(inter[j][0], x[0]);
                inter[j][1] = max(inter[j][1], x[1]);
                i++;
                flag = true;
                while(i < n && intervals[i][0] <= inter[j][1])
                {
                    inter[j][1] = max(inter[j][1], intervals[i][1]);
                    i++;
                }
                j++;
                i--;
            }
        }
        // if(l < newInterval[0])
        if(!flag)
        {
            inter.push_back(newInterval);
        }
        // intervals.push_back({s, e});
        return inter;
    }
};