// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int BinarySearchfind(vector<int> &a, int l, int r, int val)
    {
        int ans = -1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(a[mid] == val)
                return mid;
            if(a[mid] < val)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
    int removals(vector<int>& a, int k){
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = n;
        for(int i = 0; i < n; i++)
        {
            int j = BinarySearchfind(a, i, n-1, a[i]+k);
            if(j != -1)
            {
                ans = min(ans, n - (j - i + 1));
            }
        }
        return ans;
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