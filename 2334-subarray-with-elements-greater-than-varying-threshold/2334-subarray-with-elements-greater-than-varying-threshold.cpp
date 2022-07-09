class Solution {
public:
    int validSubarraySize(vector<int>& nums, int t) {
        int n = nums.size();
        vector<int> NSR(n, n), NSL(n, -1);
        stack<int> st1, st2;
        for(int i = n-1; i>= 0; i--)
        {
            while(!st1.empty() && nums[st1.top()] >= nums[i])
                st1.pop();
            if(!st1.empty())
                NSR[i] = st1.top();
            st1.push(i);
        }
        for(int i = 0; i< n; i++)
        {
            while(!st2.empty() && nums[st2.top()] >= nums[i])
                st2.pop();
            if(!st2.empty())
                NSL[i] = st2.top();
            st2.push(i);
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int len = NSR[i] - NSL[i] - 1;
            //arr[i] being minimum element
            if(nums[i] > t/len)
                ans = min(len, ans);
        }
        return ans == INT_MAX ? -1 : ans;
        
    }
};