class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return false;
        int mn1 = INT_MAX, mn2 = INT_MAX;
        // two small values we are holding, if new value isgreater that both, then we got the answer
        for(auto x : nums)
        {
            // if(x > mn1)
            // {
            //     return true;
            // }
            // else 
            if(x <= mn1)
            {
                mn1 = x;
                // mn2 = mn1;
                // mn1 = x;
            }
            else if(x <= mn2)
            {
                mn2 = x;
            }
            else
                return true;
        }
        // cout<<mn1<<" "<<mn2<<endl;
        return false;
    }
};