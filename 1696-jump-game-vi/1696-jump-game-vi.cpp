class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        deque<int> q;
        q.push_back(0);
        int j = 0;
        for(int i = 1; i < n; i++)
        {
            // int j = q.front
            if(i - q.front() > k)
                q.pop_front();
            int val = nums[q.front()] + nums[i]; 
            // bcse largest value in queue is at front only
            nums[i] = val;
            while(!q.empty() && val > nums[q.back()])
                q.pop_back();
            // jitni choti values h purani hata do, vo kaam ki nhi rahi, 
            //because badi better value aa gayi h
            q.push_back(i);
        }
        return nums[q.back()];
    }
};