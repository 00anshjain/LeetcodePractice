// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    typedef long long ll;
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<ll> st;
        st.push(-1);
        vector<ll> ans(n);
        for(int i = n-1; i>= 0; i--)
        {
            // ans[i] = st.top();
            while(!st.empty() && arr[i] >= st.top())
                st.pop();
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            while(!st.empty() && st.top() < arr[i])
                st.pop();
            st.push(arr[i]);
        }
        return ans;
        // Your code here
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends