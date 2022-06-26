// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<int> st;
        for(auto c : x)
        {
            if(c == '('|| c == '{' || c == '[')
                st.push(c);
            else
            {
                if(st.empty())
                    return false;
                if((c == ')' && st.top() == '(')||( c == '}' && st.top() == '{')|| (c == ']' && st.top() == '['))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
        // Your code here
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends