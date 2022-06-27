// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for(auto c : S)
        {
            if(c >= '0' && c<= '9')
            {
                int g = c - '0';
                st.push(g);
            }
            else
            {
                int t1 = st.top();st.pop();
                int t2 = st.top();
                st.pop();
                if(c == '+')
                    st.push(t1 + t2);
                else if(c == '-')
                    st.push(t2 - t1);
                else if(c == '/')
                    st.push(t2/t1);
                else
                    st.push(t2*t1);
            }
        }
        return st.top();
        // Your code here
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends