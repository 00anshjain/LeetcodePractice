// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        stack<int> st;
        int par = INT_MIN;
        for(int i = 0; i < N; i++)
        {
            while(!st.empty() && st.top() < arr[i])
            {
                par = st.top();
                st.pop();
            }
            if(arr[i] < par)
                return false;
            st.push(arr[i]);
        }
        return true;
        
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends