class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN, mxSum = 0, mnSum = 0, sum = 0, n = nums.size();
        for(int i = 0; i < n; i++) 
        {
            sum += nums[i];
            mxSum += nums[i];
            mnSum += nums[i];
            mx = max(mx, mxSum);
            mn = min(mn, mnSum);
            if(mxSum < 0)
                mxSum = 0;
            if(mnSum > 0)
                mnSum = 0;
        }
        // cout<<mxSum<<" "<<mnSum<<" "<<sum<<endl;
        if(mn == sum)
            return mx;
        return max(sum - mn, mx);
    }
};