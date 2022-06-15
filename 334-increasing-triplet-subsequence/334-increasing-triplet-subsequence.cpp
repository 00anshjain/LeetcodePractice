class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return false;
        int mn[n];
        int mx[n];
        mn[0] = INT_MAX;
        mx[n-1] = INT_MIN;
        for(int i = 1; i < n; i++)
        {
            mn[i] = min(mn[i-1], nums[i-1]);
            mx[n-i-1] = max(mx[n-i], nums[n-i]);
        }
        for(int i = 1; i < n-1; i++)
        {
            if(mn[i] < nums[i] && mx[i] > nums[i])
                return true;
        }
        return false;
        
    }
};