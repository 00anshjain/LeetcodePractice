class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st1, st2;
        int n = heights.size();
        vector<int> nsl(n), nsr(n);
        //nsl -> nearest shorter to left
        //nsr -> nearest shorter to right
        for(int i = 0; i < n; i++)
        {
            while(!st1.empty() && heights[st1.top()] >= heights[i])
                st1.pop();
            if(st1.empty())
                nsl[i] = -1;
            else
                nsl[i] = st1.top();
            st1.push(i);
        }
        for(int i = n-1; i >= 0; i--)
        {
            while(!st2.empty() && heights[st2.top()] >= heights[i])
                st2.pop();
            if(st2.empty())
                nsr[i] = n;
            else
                nsr[i] = st2.top();
            st2.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            // cout<<nsl[i]<<" "<<nsr[i]<<endl;
            ans = max(ans, heights[i] * (nsr[i] - nsl[i] - 1));
        }return ans;
    }
};