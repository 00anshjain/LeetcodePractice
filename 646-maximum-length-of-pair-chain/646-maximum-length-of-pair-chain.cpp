class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        int t = -1001;
        int mx = 0;
        for(int i = 0; i < n; i++)
        {
            if(pairs[i][0] > t)
            {
                mx++;
                t = pairs[i][1];
            }
            else if(pairs[i][1] < t)
                t = pairs[i][1];
        }
        return mx;
    }
};