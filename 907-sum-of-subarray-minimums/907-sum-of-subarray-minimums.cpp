class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> lmin(n, 0), rmin(n, n-1);
        stack<int> st1, st2;
        int mod = 1e9+7;
        for(int i = 0; i < n; i++)
        {
            while(!st1.empty() && arr[st1.top()] > arr[i])
                st1.pop();
            if(!st1.empty())
                lmin[i] = st1.top() + 1;
            st1.push(i);
        }
        for(int i = n-1; i >= 0; i--)
        {
            while(!st2.empty() && arr[st2.top()] >= arr[i])
                st2.pop();
            if(!st2.empty())
                rmin[i] = st2.top() - 1;
            st2.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += (((long long)arr[i] * ((long long)i - lmin[i] + 1)*((long long)rmin[i] - i + 1))%mod );
        }
        return ans%mod;
        
        
    }
};