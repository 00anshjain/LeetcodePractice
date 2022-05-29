class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n -1;
        while(left <= right)
        {
            if(nums[left] <= nums[right])
                return nums[left];
            int mid = left + (right - left)/2;
            if(nums[mid] <= nums[(mid + 1)%n] && nums[mid] <= nums[(mid-1+n) % n])
                return nums[mid];
            else if(nums[left] <= nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};