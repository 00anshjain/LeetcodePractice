// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> specialXor(int N, int Q, int a[], vector<int> query[])
    {
        int b[N];
        b[0] = a[0];
        for(int i = 1; i < N; i++)
            b[i] = a[i]^b[i-1];
        vector<int> res;
        for(int k = 0; k < Q; k++)
        {
            int ans = b[N-1];
            int i = query[k][0];
            int j = query[k][1];
            i--;
            j--;
            if(i > 0)
                ans ^= b[i-1];
            if(j >= 0)
                ans ^= b[j];
            res.push_back(ans);
        }
        return res;
        // code here
    }
}; 

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int a[N];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        int l, r;
        vector<int> query[Q];
        for(int i = 0;i < Q;i++){
            cin>>l>>r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
        
        Solution ob;
        vector<int> ans = ob.specialXor(N, Q, a, query);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}  // } Driver Code Ends