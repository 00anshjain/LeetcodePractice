class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        // int dp[n];
        int notTakenLast = nums[0];
        int takenLast = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++)
        {
            int nnotTakenLast = max(takenLast, notTakenLast);
            takenLast = notTakenLast + nums[i];
            notTakenLast = nnotTakenLast;
            // dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return max(notTakenLast, takenLast);
    }
};