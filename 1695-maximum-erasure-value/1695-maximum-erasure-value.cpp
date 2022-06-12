class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // unordered_set<int> st(nums.begin(), nums.end());
        // return accumulate(st.begin(), st.end(), 0);
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        int n = nums.size();
        while(j < n)
        {
            sum += nums[j];
            mp[nums[j]]++;
            while(mp[nums[j]] > 1)
            {
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, sum);
            j++;
        }
        return ans;
    }
};