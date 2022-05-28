class Solution {
public:
    vector<int> NSL(vector<int> &arr, int n)
    {
        vector<int> left(n);
        stack<int> st;
        for(int i = 0;i < n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
        return left;
    }
    vector<int> NSR(vector<int> &arr, int n)
    {
        vector<int> right(n);
        stack<int> st;
        for(int i = n-1;i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
        return right;
    }
    int maximumAreaHistogram(vector<int> &arr, int n)
    {
        vector<int> left = NSL(arr, n);
        vector<int> right = NSR(arr, n);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i] * (right[i] -left[i] - 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < n; i++)
        {   if(matrix[0][i] == '1')
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }
        // vector<int> v()
        vector<int> v(dp[0].begin(), dp[0].end()); 
        // int ans = maximumAreaHistogram(dp[0], n);
        int ans = maximumAreaHistogram(v, n);
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {   if(matrix[i][j] == '1')
                    dp[i][j] = dp[i-1][j] + 1;
                else
                    dp[i][j] = 0;
            }
            vector<int> v(dp[i].begin(), dp[i].end()); 
            ans = max(ans, maximumAreaHistogram(v, n));
        }
        return ans;
    }
};