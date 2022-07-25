class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0;
        int n = nums.size();
        int j = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
                zero++;
            while(zero > k)
            {
                if(nums[j] == 0)
                    zero--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};