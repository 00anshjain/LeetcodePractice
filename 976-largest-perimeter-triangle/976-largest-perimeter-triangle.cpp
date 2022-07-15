class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < n-2; i++)
        {
            int j = i+1;
            int k = j+1;
            if(nums[i] + nums[j] > nums[k]  && nums[i] + nums[k] > nums[j] && nums[k] + nums[j] > nums[i])
            {
                return nums[i] + nums[j] + nums[k];
            }
        }
        // for(int i = 0; i < n-2; i++)
        // {
        //     for(int j = i+1; j < n-1; j++)
        //     {
        //         for(int k = j+1; k < n; k++)
        //         {
        //             
        //         }
        //     }
        // }
        return ans;
    }
};