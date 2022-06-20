class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx = INT_MIN, mxSum = 0;
        int mn = INT_MAX, mnSum = 0;
        int sum = 0;
        for(auto x : nums)
        {
            sum += x;
            mxSum += x;
            mnSum += x;
            if(mxSum > mx)
                mx = mxSum;
            if(mnSum < mn)
                mn = mnSum;
            if(mxSum < 0)
                mxSum = 0;
            if(mnSum > 0)
                mnSum = 0;
        }
        // cout<<mx<<" "<<mn<<endl;
        if(sum == mn)
            return mx;
            // return *max_element(nums.begin(), nums.end());
        
        return max(sum - mn, mx);
        
    }
};