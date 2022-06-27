class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int mx1 = 0, mx2 = 0;
        int sum1 = 0, sum2 = 0;
        int currSum1 = 0, currSum2 = 0;
        for(int i = 0; i < n; i++)
        {
            sum1 += nums1[i];
            sum2 += nums2[i];
            currSum1 += (nums2[i] - nums1[i]);
            currSum2 += (nums1[i] - nums2[i]);
            mx1 = max(currSum1, mx1);
            mx2 = max(currSum2, mx2);
            if(currSum1 < 0)
                currSum1 = 0;
            if(currSum2 < 0)
                currSum2 = 0;
        }
        int ans = max(sum1, sum2);
        ans = max(ans, sum1 + mx1);
        ans = max(ans, sum2 + mx2);
        return ans;
        
    }
};