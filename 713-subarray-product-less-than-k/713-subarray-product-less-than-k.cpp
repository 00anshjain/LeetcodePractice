class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j = 0, i = 0;
        int n = nums.size();
        int pro = 1;
        int ans = 0;
        // if(k == 0)
        //     return 0;
        for(int i = 0; i < n; i++)
        {
            pro *= nums[i];
            while(pro >= k && i >= j)
            {
                pro /= nums[j];
                j++;
            }
            if(pro <= k)
                ans += i - j + 1;
            // i++;
        }
        return ans;
    }
};