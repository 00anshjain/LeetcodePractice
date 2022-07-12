class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int i = 0;
        int arrow = 0;
        int n = points.size();
        while(i < n)
        {
            int end = points[i][1];
            arrow++;
            while(i < n && points[i][0] <= end)
            {
                i++;
            }
        }
        return arrow;
    }
};