class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0];
        int mn = nums[0];
        int currMx = nums[0];
        int currMn = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            int cMax = max(max(currMx*nums[i], currMn*nums[i]),nums[i]);
            int cMin = min(min(currMx*nums[i], currMn*nums[i]), nums[i]);
            currMx = cMax;
            currMn = cMin;
            mx = max(mx, currMx);
            mn = min(mn, currMn);
        }
        return mx;
    }
};