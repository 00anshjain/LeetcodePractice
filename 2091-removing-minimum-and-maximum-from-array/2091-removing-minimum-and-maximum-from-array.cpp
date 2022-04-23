class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // bool leftdir1 = false;
        // bool leftdir2 = false;
        int mn = nums[0], mnIdx = 0, mx = mn, mxIdx = mnIdx;
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(mx < nums[i])
            {
                mxIdx = i;
                mx = nums[i];
            }
            if(mn > nums[i])
            {
                mnIdx = i;
                mn = nums[i];
            }
        }
        int ans1 = min(max(mnIdx, mxIdx) + 1, max(n-mnIdx, n-mxIdx));
        int ans2 = min(mnIdx+1 + n-mxIdx, n-mnIdx + mxIdx+1);
        // cout<<mxIdx<<" "<<mnIdx<<endl;
        // cout<<ans1<<" "<<ans2<<endl;
        return min(ans1, ans2);
        
    }
};