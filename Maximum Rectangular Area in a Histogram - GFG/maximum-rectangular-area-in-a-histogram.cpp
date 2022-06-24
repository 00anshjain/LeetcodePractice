// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    typedef long long ll;
    long long getMaxArea(long long arr[], int n)
    {
        vector<ll> stl(n, 0), str(n, n-1);
        stack<int> st1, st2;
        st1.push(0);
        for(int i = 1; i < n; i++)
        {
            while(!st1.empty() && arr[st1.top()] >= arr[i])
                st1.pop();
            if(!st1.empty())
            //     stl[i]= -1;
            // else
                stl[i] = st1.top()+1;
            st1.push(i);
        }
        st2.push(n-1);
        for(int i = n-2; i >= 0; i--)
        {
            while(!st2.empty() && arr[st2.top()] >= arr[i])
                st2.pop();
            if(!st2.empty())
            //     stl[i]= -1;
            // else
                str[i] = st2.top()-1;
            st2.push(i);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i]*(str[i] - stl[i]+1));
        }
        return ans;
        
        // Your code here
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends