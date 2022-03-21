class Solution {
public:
    void helper(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int> curr)
    {
        if(i == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        helper(i+1, nums, ans, curr);
        curr.push_back(nums[i]);
        helper(i+1, nums, ans, curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i = 0;
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, nums, ans, curr);
        return ans;
        
    }
};