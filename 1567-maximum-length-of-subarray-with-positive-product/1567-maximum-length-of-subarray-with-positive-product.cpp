class Solution {
public:
    int getAns(vector<int>& nums, int l, int r)
    {
        int lneg = l-1, rneg = r+1;
        int pro = 1;
        for(int i = l; i <= r; i++)
        {
            pro *= (nums[i] < 0 ? -1 : 1);
            if(nums[i] < 0 && lneg == l - 1)
                lneg = i;
            if(nums[i] < 0)
                rneg = i;
        }
        
        // cout<<lneg<<" "<<rneg<<" "<<l<<" "<<r<<endl;
        if(pro > 0)
            return r-l+1;
        // int ans = 0;
//         cout<<lneg - l<<endl;
//         cout<<r - lneg<<endl;
//         cout<<rneg - l<<endl;
//         cout<<r - rneg<<endl;
        
        return max({lneg - l, r - lneg, rneg - l, r - rneg});
        // if(lneg > l-1)
        //     ans = max(ans, )
        // if(pro < 0)
        // {
        //     return max({getAns(nums, lneg+1, r), getAns(nums, l, rneg-1)});
        // }
        return 0;
    }
    int getMaxLen(vector<int>& nums) {
        int i = -1;
        int n = nums.size();
        int ans = 0;
        for(int j = 0; j < n; j++)
        {
            if(nums[j] == 0)
            {
                ans = max(ans, getAns(nums, i+1, j-1));
                // cout<<ans<<endl;
                i = j;
            }
        }
        if(nums[n-1] != 0)
            ans = max(ans, getAns(nums, i+1, n-1));
        
        return ans;
    }
};