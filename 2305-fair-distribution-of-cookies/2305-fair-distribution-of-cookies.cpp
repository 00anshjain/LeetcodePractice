class Solution {
public:
    int res;
    int K;
    void recur(int n, vector<int> &arr, vector<int> &v, int sum)
    {
        if(n == 0)
        {
            res = min(res, sum);
        }
        if(sum >= res)
            return;
        for(int i = 0; i < K; i++)
        {
            v[i] += arr[n-1];
            int newSum = max(sum, v[i]);
            recur(n-1, arr, v, newSum);
            v[i] -= arr[n-1];
        }
    }
    int distributeCookies(vector<int>& arr, int k) {
        vector<int> v(k, 0);
        K = k;
        res = INT_MAX;
        recur(arr.size(), arr, v, 0);
        return res;
    }
};