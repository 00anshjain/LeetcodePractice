class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return false;
        int first_min = INT_MAX, second_min = INT_MAX;
        for(auto x : nums)
        {
            if(x <= first_min)
            {
                first_min = x;
            }
            else if(x <= second_min)
            {
                second_min = x;
            }
            else
                return true;
        }
        return false;
    }
};