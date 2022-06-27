class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        //stack will contain the last unvalid poition
        st.push(-1);
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    ans = max(ans, i - st.top()); //since st.top() contains nearest invalid poition
                }
                else
                {
                    st.push(i); //this means this closing bracket is extra and hence invalid so we add it to stack
                }
            }
        }
        return ans;
    }
};