class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // if(ans != nums.size() && nums[ans] != target)
        //     return ans -1;
        return ans;
            
    }
};