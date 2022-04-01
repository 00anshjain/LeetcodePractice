class Solution {
public:
    int partition(vector<int>& q, int mid)
    {
        int p = 0;
        for(auto x : q)
        {
            p += (x/mid + (x%mid > 0 ? 1 : 0));
            // while(x > 0)
            // {
            //     x -= mid;
            //     p++;
            // }
        }
        return p;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int right = INT_MIN;
        for(auto x : q)
        {
            // mn = min(mn, x);
            right = max(right, x);
        }
        int left = 1;
        int ans = 0;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(partition(q, mid) <= n)
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};