class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int j = 0, n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if(i < k-1)
                continue;
            if(q.front() < j)
                q.pop_front();
            ans.push_back(nums[q.front()]);
            j++;
        }
        return ans;
    }
};