// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i = 0; i < n; i++)
            st.push(i);
        int celeb;
        while(!st.empty())
        {
            int p1 = st.top();
            st.pop();
            if(st.empty())
            {
                celeb = p1;
                break;
            }
            int p2 = st.top();
            st.pop();
            if(M[p1][p2])
            {
                //means p1 knows p2 
                // so p1 cant be celebrity its out now
                st.push(p2);
            }
            else
            {
                //since p2 is not known by p1 so p2 cant be celebrity its out now
                st.push(p1);
            }
        }
        //Now we check the celeb we have got is realley celebrity or not
        // we check celebrity with everyone
        
        for(int i = 0; i < n; i++)
        {
            if((i != celeb) && (M[celeb][i] || !M[i][celeb]))
                return -1;
        }
        return celeb;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends