// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int n,vector<int> &A,vector<int> &B){
        // int n = A.size();
        stack<int> st;
        int j = 0, i = 0;
        while(i < n)
        {
            while(i < n && (st.empty() || st.top() != B[j]))
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

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends