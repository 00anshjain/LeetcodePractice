class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int  t= arr[0][0], end = arr[0][1];
        int n = arr.size();
        for(int i = 1; i < n; i++)
        {
            if(arr[i][0] > end)
            {
                ans.push_back({t, end});
                t = arr[i][0];
                end = arr[i][1];
            }
            else
            {
                end = max(end, arr[i][1]);
            }
        }
        ans.push_back({t, end});
        return ans;
    }
};