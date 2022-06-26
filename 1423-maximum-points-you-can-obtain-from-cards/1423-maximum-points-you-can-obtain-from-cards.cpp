class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        if(k >= n)
            return accumulate(cp.begin(), cp.end(), 0);
        vector<int> arr(n+1, 0);
        for(int i = 1; i <= n; i++)
            arr[i] = cp[i-1] + arr[i-1];
        int ans = arr[k];
        int t = n-1;
        int sum2 = 0;
        k -= 1;
        while(k >= 0)
        {
            // sum2 += arr[t];
            sum2 += cp[t];
            ans = max(ans, arr[k]+sum2);
            t--;
            k--;
        }
        return ans;
    }
};