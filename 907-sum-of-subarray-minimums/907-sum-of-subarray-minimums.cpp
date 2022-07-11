class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL(n, -1), NSR(n, n);
        stack<int> st1;
        for(int i = 0; i < n; i++)
        {
            while(!st1.empty() && arr[st1.top()] > arr[i])
                st1.pop();
            if(!st1.empty())
                NSL[i] = st1.top();
            st1.push(i);
        }
        stack<int> st2;
        for(int i = n-1; i >= 0; i--)
        {
            while(!st2.empty() && arr[st2.top()] >= arr[i])
                st2.pop();
            if(!st2.empty())
                NSR[i] = st2.top();
            st2.push(i);
        }
        ll sum = 0l;
        for(int i = 0; i < n; i++)
        {
            sum += (ll)arr[i]*(i - (ll)NSL[i])*(NSR[i]-i);
            sum%= mod;
        }
        return sum;
        
        
    }
};