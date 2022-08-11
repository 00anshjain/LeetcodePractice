class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);//, right(n);
        vector<int> pre(n+1, INT_MAX), pre2(n+1, INT_MAX);
        pre[0] = INT_MIN;
        pre2[0] = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int cnt = lower_bound(pre.begin(), pre.end(), nums[i]) - pre.begin();
            left[i] = cnt;
            pre[cnt] = nums[i];
        }
        int ans = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int cnt = lower_bound(pre2.begin(), pre2.end(), nums[i]) - pre2.begin();
            // left[i] = cnt;
            // if(i != 0 && i != n-1)
            if(left[i] != 1 && cnt != 1)
                ans = max(ans, left[i] + cnt - 1); //-1 because this element is counted two times
            pre2[cnt] = nums[i];
        }
        // cout<<ans<<" "<<endl;
        return n - ans;
        
    }
};