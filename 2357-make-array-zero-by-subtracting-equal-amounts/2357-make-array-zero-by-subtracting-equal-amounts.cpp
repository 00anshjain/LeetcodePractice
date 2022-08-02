class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        int last  = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == last)
                continue;
            else
            {
                cnt++;
                last = nums[i];
            }
        }
        return cnt;
    }
};