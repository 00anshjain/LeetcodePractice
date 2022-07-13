class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        int n = p.size();
        double ans = 0.0;
        for(int i = 0; i < n-2; i++)
        {
            for(int j = i+1; j < n-1; j++)
            {
                for(int k = j+1; k < n; k++)
                {
                    double s1 = sqrt(1.0*(p[i][0] - p[j][0])*(p[i][0] - p[j][0]) + (p[i][1] - p[j][1])*(p[i][1] - p[j][1]));
                    double s2 = sqrt(1.0*(p[i][0] - p[k][0])*(p[i][0] - p[k][0]) + (p[i][1] - p[k][1])*(p[i][1] - p[k][1]));
                    double s3 = sqrt(1.0*(p[k][0] - p[j][0])*(p[k][0] - p[j][0]) + (p[k][1] - p[j][1])*(p[k][1] - p[j][1]));
                    double s = (s1 + s2 + s3)/2.0;
                    ans = max(ans, sqrt(s*(s-s1)*(s-s2)*(s-s3)));
                }
            }
        }
        return ans;
    }
};