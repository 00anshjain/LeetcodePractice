class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c  : s)
        {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                // bool x = (c == ']');
                // cout<<"OK "<<c<< " "<<x<<endl;
                if(st.empty())
                    return false;
                if (c == ')')
                {
                    cout<<"Yes0"<<endl;
                    if(st.top() != '(')
                        return false;
                }
                else if(c == ']')
                {
                    cout<<"Yes1"<<endl;
                    if(st.top() != '[')
                        return false;
                }
                else if(c == '}')
                {
                    cout<<"Yes3"<<endl;
                    if(st.top() != '{')
                        return false;
                }
                else
                    return false;
                st.pop();
            }
        }
        if(st.empty())
            return true;
        return false;
        
    }
};