class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
         sort(intervals.begin(), intervals.end());
         vector<vector<int>> ans;
         int t = -1;
         int j = -1;
         for(int i = 0; i < n; i++)
         {
             if(intervals[i][0] > t)
            {
                j++;
                ans.push_back(intervals[i]);
                t = intervals[i][1];
            }
            else
            {
                ans[j][1] = max(ans[j][1], intervals[i][1]);
                t = ans[j][1];
            }
         }
         return ans;
    }
};