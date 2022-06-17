class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int cnt = 0;
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i < n-1; i++)
        {
            mx = max(mx, i + nums[i]);
            if(cnt == 0)
            {
                jump++;
                cnt += mx - i;
            }
            cnt--;
        }
        return jump;
    }
};