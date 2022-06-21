class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i-1 >= 0 && nums[i-1] >= nums[i])
            i--;
        // 1 5 3 2 0
        //  5 4 3 2 1
        if(i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int left = i-1;
        int j = n-1;
        while(nums[j] <= nums[left])
            j--;
        // while(j < n && left < nums[j])
        //     j++;
        swap(nums[left], nums[j]);
        reverse(nums.begin() + left + 1, nums.end());
        return;
        
        
        
        // int i = 0;
        // // 1, 2, 3, 4, 5, 6
        // while(i+1 < n && nums[i+1] >= nums[i])
        // {
        //     i++;
        // }
        // // i at 6
        // if(i == n-1)
        // {
        //     swap(nums[i], nums[i-1]);
        //     return nums;
        // }
        // // 1,2 ,3, 6, 5, 4, 7
        // while(i + 1 < n && nums[i+1] < nums[i])
        //     i++;
        // while(i+1 < n && nums[i+1] >= nums[i])
        // {
        //     i++;
        // }
    }
};