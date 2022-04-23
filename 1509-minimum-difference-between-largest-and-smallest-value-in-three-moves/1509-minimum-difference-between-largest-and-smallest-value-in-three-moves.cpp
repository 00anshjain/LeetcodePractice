class Solution {
public:
    int minDifference(vector<int>& nums) {
       int n = nums.size();
        if(n <= 4)
            return 0;
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < 4; i++)
        {
            ans = min(ans, nums[n-i-1]-nums[3-i]);
        }
        return ans;
    }
};