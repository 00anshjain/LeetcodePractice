class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int n = nums.size();
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return true;
            if(nums[r] == nums[mid])
            {
                r--;
                continue;
            }
            if(nums[l] == nums[mid])
            {
                l++;
                continue;
            }
            
            if(nums[r] >= nums[mid])
            {
                if(target > nums[mid] && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else if(nums[mid] >= nums[l])
            {
                if(target < nums[mid] && target >= nums[l])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
                return false;
                // l++;
        }
        return false;
    }
};