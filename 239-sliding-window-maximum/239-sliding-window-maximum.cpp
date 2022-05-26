class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int i = 0, j = 0;
        deque<int> q;
        vector<int> res;
        int n = arr.size();
        while(j < n)
        {
            if(q.empty())
                q.push_back(arr[j]);
            else{
                while(!q.empty() && q.back() < arr[j])
                    q.pop_back();
                q.push_back(arr[j]);
            }
            if(j-i+1 < k)
            {  
                j++;
            }
            else
            {
                res.push_back(q.front());
                if(arr[i] == q.front())
                    q.pop_front();
                i++;
                j++;
            }
        }
        return res;
    }
};