class Solution {
public:
    bool validateStackSequences(vector<int>& A, vector<int>& B) {
        int n = A.size();
        stack<int> st;
        int j = 0, i = 0;
        while(i < n)
        {
            if(st.empty() || st.top() != B[j])
            {
               st.push(A[i]);
               i++;
            }
            if(st.top() == B[j])
            {
                st.pop();
                j++;
            }
        }
        while(j < n)
        {
            if(st.empty())
                return false;
            if(st.top() != B[j])
                return false;
            st.pop();
            j++;
        }
        return true;
    }
};