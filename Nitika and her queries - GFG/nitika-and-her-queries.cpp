// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


const int mxi = 1e5+2;
class Solution{
public:
    int seg[4*mxi];
    void buildSeg(int arr[], int idx, int l, int r)
    {
        if(l == r)
        {
            seg[idx] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        buildSeg(arr, 2*idx+1, l, mid);
        buildSeg(arr, 2*idx+2, mid+1, r);
        seg[idx] = seg[2*idx+1]^seg[2*idx+2];
    }
    //we have to find xor of l to r
    int getAns(int idx, int low, int high, int l, int r)
    {
        if(l > high || r < low)
            return 0;
        if(l <= low && r >= high)
            return seg[idx];
        int mid = (low+high)/2;
        int op1 = getAns(2*idx+1, low, mid, l, r);
        int op2 = getAns(2*idx+2, mid+1, high, l, r);
        return op1^op2;
    }
    vector<int> specialXor(int n, int q, int arr[], vector<int> query[])
    {
        buildSeg(arr, 0, 0, n-1);
        int XOR = 0;
        for(int i = 0; i< n; i++)
            XOR ^= arr[i];
        vector<int> ans;
        for(int k = 0; k < q; k++)
        {
            int low = query[k][0]-1;
            int high = query[k][1]-1;
            ans.push_back(XOR^getAns(0, 0, n-1, low, high));
        }
        return ans;
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