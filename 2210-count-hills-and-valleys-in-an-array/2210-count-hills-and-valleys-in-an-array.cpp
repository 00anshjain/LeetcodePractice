class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 1; i < n-1; i++)
        {
            int j = i-1;
            if(nums[j] == nums[i])
                continue;
            // while(j >= 0 && nums[j] == nums[i])
            //     j--;
            if(j < 0)
                continue;
            int k = i+1;
            while(k < n && nums[k] == nums[i])
                k++;
            if(k == n)
                continue;
            if((nums[k] < nums[i] && nums[j] <nums[i]) || (nums[k] > nums[i] && nums[j] >nums[i]))
            {
                cout<<i<<" ";
                cnt++;
            }
        }
        return cnt;
    }
};