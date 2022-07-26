class Solution {
public:
    void recur(int i, int k, int n, vector<vector<int>>& res, vector<int>& curr)
    {
        curr.push_back(i);
        if(k == 0)
        {
            res.push_back(curr);
            curr.pop_back();
            return;
        }
        for(int j = i+1; j <= n; j++)
        {
            recur(j, k-1, n, res, curr);
        }
        curr.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        for(int i = 1; i <= n; i++)
        {
            recur(i, k-1, n, res, curr);
        }
        return res;
    }
};