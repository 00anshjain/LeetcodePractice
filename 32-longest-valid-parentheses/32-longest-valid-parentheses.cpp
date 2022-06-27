class Solution {
public:
    int longestValidParentheses(string s) {
        // stack<int> st;
        //stack will contain the last unvalid poition
        // st.push(-1);
        int n = s.size();
        int start_bracket = 0;
        int end_bracket = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                start_bracket++;
            else
            {
                end_bracket++;
                if(start_bracket == end_bracket)
                {
                    ans = max(ans, 2*end_bracket);
                }
                else if(end_bracket > start_bracket)
                {
                    start_bracket = 0;
                    end_bracket = 0;
                }
            }
        }
        // Now consider -> "()((()()"
        // For this we start from backwards and similaryly like abvove, if we have 
        // start_bracket > end_bracket, then we break and reset start and end to zero;
        start_bracket = 0;
        end_bracket = 0;
        // int ans2 = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == ')')
                end_bracket++;
            else
            {
                start_bracket++;
                if(end_bracket == start_bracket)
                {
                    ans = max(ans, 2*start_bracket);
                }
                else if(start_bracket > end_bracket)
                {
                    start_bracket = 0;
                    end_bracket = 0;
                }
            }
        }
        
        return ans;
    }
};