class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // vector<int> nums2(n);
        int xorr = 0;
        for(int i = 0; i < n; i++)
        {
            xorr ^= i;
            xorr ^= nums[i];
        }
        xorr ^= n;
        return xorr;
    }
};