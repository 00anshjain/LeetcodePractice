// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int hcf(int a, int b)
    {
        if(b > a)
            return(hcf(b, a));
        if(b == 0)
            return a;
        return hcf(b, a%b);
            
    }
    void buildSeg(vector<int> &seg, int arr[], int idx, int l, int r)
    {
        if(l == r)
        {
            seg[idx] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        buildSeg(seg, arr, 2*idx+1, l, mid);
        buildSeg(seg, arr, 2*idx+2, mid+1, r);
        seg[idx] = hcf(seg[2*idx+1], seg[2*idx+2]);
    }
    int getQuery(vector<int> &seg, int idx, int low, int high, int l, int r)
    {
        if(l > high || r < low)
            return -1;
        if(high <= r && low >= l)
            return seg[idx];
        int mid = (low+high)/2;
        int op1 = getQuery(seg, 2*idx+1, low, mid, l, r);
        int op2 = getQuery(seg, 2*idx+2, mid+1, high, l, r);
        if(op1 == -1)
            return op2;
        if(op2 == -1)
            return op1;
        return hcf(op1, op2);
    }
    int findSmallestSubArr(int arr[], int n, int g) {
       vector<int> seg(4*n+1);
    //   cout<<"Tree in progress"<<endl;
       buildSeg(seg, arr, 0, 0, n-1);
    //   cout<<"Tree made"<<endl;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == g)
                return 1;
        }
        int ans = n+1;
        for(int start = 0; start < n; start++)
        {
            if(arr[start] %g != 0)
                continue;
            int low = start+1, high = n-1;
            while(low <= high)
            {
                int mid = (low+high)/2;
                int z = getQuery(seg, 0, 0, n-1, start, mid);
                if(z > g)
                    low = mid+1;
                else if(z < g)
                    high = mid - 1;
                else
                {
                    ans = min(ans, mid-start+1);
                    high = mid - 1;
                }
            }
        }
        return ans == n+1 ? -1: ans;
    //   for(int sz = 1; sz <= n; sz++)
    //   {
    //       int i = 0;
    //       int j = sz-1;
    //       while(j < n)
    //       {
    //           if(getQuery(seg, 0, 0, n-1, i, j) == g)
    //           {
    //             return sz;
    //           }
    //             i++;
    //             j++;
    //         }
    //   }
    //   return -1;
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, g;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> g;
        Solution ob;
        auto ans = ob.findSmallestSubArr(arr, n, g);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends