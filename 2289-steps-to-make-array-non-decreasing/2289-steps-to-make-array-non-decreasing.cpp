class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>> st;
        int ans = 0;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--)
        {
            int cnt = 0;
            while(!st.empty() && nums[st.top().first] < nums[i])
            {    
                cnt = max(cnt+1, st.top().second);
                st.pop();
            }
            ans = max(ans, cnt);
            st.push({i, cnt});
        }
        return ans;
        
    }
};