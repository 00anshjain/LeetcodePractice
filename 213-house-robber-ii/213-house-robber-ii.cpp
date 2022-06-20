class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return nums[0];
        int notTaken = nums[0];
        int taken = nums[1];
        for(int i = 2; i < n-1; i++)
        {
            int newnotTaken = max(taken, notTaken);
            taken = notTaken + nums[i];
            notTaken = newnotTaken;
        }
        int ans1 = max(notTaken, taken);
        // return ans1;
        int ans2 = 0;
        notTaken = 0;
        taken = nums[1];
        for(int i = 2; i < n; i++)
        {
            int newnotTaken = max(taken, notTaken);
            taken = notTaken + nums[i];
            notTaken = newnotTaken;
        }
        ans2 = max(taken, notTaken);
        return max(ans1, ans2);
        // return 0;
        
    }
};