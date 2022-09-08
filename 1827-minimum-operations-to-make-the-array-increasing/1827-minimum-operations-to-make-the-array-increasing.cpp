class Solution {
public:
    int minOperations(vector<int>& nums) {
        // int n = nums.size();
        // for(int i = 1; i < n; i++)
        int l = -1;
        int ans = 0;
        for(auto x : nums)
        {
            if(x > l)
                l = x;
            else
            {
                ans += (l+1 - x);
                l = l+1;
            }
        }
        return ans;
    }
};