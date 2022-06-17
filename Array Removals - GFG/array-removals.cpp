// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        int steps = INT_MAX;
        sort(a.begin(), a.end());
        int n = a.size();
        for(int i = 0; i < n; i++)
        {
            int mn = a[i];
            int mx = a[i];
            for(int j = i; j < n; j++)
            {
                mn = min(a[j], mn);
                mx = max(a[j], mx);
                if(mx - mn <= k)
                {
                    steps = min(steps, n - (j-i+1));
                }
                else
                    break;
                
            }
        }
        return steps;
        //Code here
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends