// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
  public:
    vector<int> maxPrefixes(int a[], int L[], int R[], int N, int Q) {
        vector<int> pre(N);
        pre[0] = a[0];
        for(int i = 1; i < N; i++)
            pre[i] = pre[i-1] + a[i];
        vector<int> res;
        for(int i = 0; i < Q; i++)
        {
            int k = 0;
            int ans = INT_MIN;
            for(int j = L[i]; j <= R[i]; j++)
            {
                k += a[j];
                ans = max(ans, k);
                // if(k < 0)
                //     k = 0;
            }
            res.push_back(ans);
        }
        return res;
    }   
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[n], L[q], R[q];
        
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < q; i++) cin >> L[i] >> R[i];
        Solution obj;
        vector<int> ans = obj.maxPrefixes(a, L, R, n, q);
        for (auto it : ans) 
            cout << it << " ";
        cout << endl;
    }
}
  // } Driver Code Ends