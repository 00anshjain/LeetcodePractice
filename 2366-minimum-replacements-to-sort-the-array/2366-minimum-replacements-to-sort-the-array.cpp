class Solution {
public:
    typedef long long ll;
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        ll prev = nums[n-1];
        // ll cnt = 0l;
        ll ans = 0l;
        for(int i = n-2; i >= 0; i--)
        {
            int noOfTimes = nums[i]/prev;
            if(nums[i]%prev != 0)
            {
                noOfTimes++;
                prev = nums[i]/noOfTimes;
            }
            ans += (noOfTimes - 1);
        }
        return ans;
    }
};