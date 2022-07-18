class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr.size());
        int n = arr.size();
        pre[0] = arr[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1]^arr[i];
        vector<int> ans;
        for(auto x : queries)
        {
            int k = 0;
            if(x[0] != 0)
                k = pre[x[0] - 1];
            ans.push_back(pre[x[1]]^k);
        }
        return ans;
    }
};