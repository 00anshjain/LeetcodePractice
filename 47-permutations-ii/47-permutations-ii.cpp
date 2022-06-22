class Solution {
public:
    void recur(int sz, int n, vector<int> &nums, vector<bool> &taken, vector<vector<int>> &ans, set<vector<int>>& st, vector<int>& curr)
    {
        if(st.find(curr) != st.end())
            return;
        st.insert(curr);
        if(sz == n)
        {
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i< n; i++)
        {
            if(!taken[i])
            {
                taken[i] = true;
                curr.push_back(nums[i]);
                recur(sz+1, n, nums, taken, ans, st, curr);
                curr.pop_back();
                taken[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> taken(n, false);
        set<vector<int>> st;
        vector<int> curr; 
        recur(0, n, nums, taken, ans, st, curr);
        return ans;
    }
};