class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2)
    {
        return v1[0] < v2[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int i = 0;
        int end = points[i][1];
        int arrow = 1;
        int n = points.size();
        // end = 0;
        for(int i = 1; i < n; i++)
        {
            if(points[i][0] <= end)
            {
                end = min(end, points[i][1]);
            }
            else
            {
                arrow++;
                end = points[i][1];
            }
        }
        return arrow;
    }
};