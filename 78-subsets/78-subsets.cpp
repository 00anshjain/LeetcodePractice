class Solution {
public:
    void recur(vector<int> &nums, int n, vector<int> arr, vector<vector<int>> &res)
    {
        if(n == 0)
        {
            // sort(arr.begin(), arr.end());
            res.push_back(arr);
            return;
        }
        recur(nums, n-1, arr, res);
        arr.push_back(nums[n-1]);
        recur(nums, n-1, arr, res);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> res;
        recur(nums, nums.size(), arr, res);
        return res;
    }
};