class Solution {
public:
    void recur(vector<int> &nums, int n, vector<int> arr, set<vector<int>> &res)
    {
        if(n == 0)
        {
            sort(arr.begin(), arr.end());
            res.insert(arr);
            return;
        }
        recur(nums, n-1, arr, res);
        arr.push_back(nums[n-1]);
        recur(nums, n-1, arr, res);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> arr;
        // vector<vector<int>> res;
        recur(nums, nums.size(), arr, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};