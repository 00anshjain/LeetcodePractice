class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        if(k >= n)
            return {*max_element(nums.begin(), nums.end())};
        // q.push(nums[0]);
        for(int i = 0; i < k-1; i++)
        {
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
        }
        vector<int> ans;
        int j = 0;
        for(int i = k -1 ; i < n; i++)
        {
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if(q.front() < j)
                q.pop_front();
            j++;
            ans.push_back(nums[q.front()]);
        }
        return ans;
        
    }
};