// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int firstOcc(vector<int> &arr, int n, int x)
    {
        int left = 0, right = n-1;
        int ans = -1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(arr[mid] > x)
                right = mid - 1;
            else if(arr[mid] < x)
                left = mid + 1;
            else
            {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
    int lastOcc(vector<int> &arr, int n, int left, int x)
    {
        int right = n-1;
        int ans = -1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(arr[mid] > x)
                right = mid - 1;
            else if(arr[mid] < x)
                left = mid + 1;
            else
            {
                // cout<<mid<<"    ."<<endl;
                ans = mid;
                left = mid+1;
                // right = mid - 1;
            }
        }
        return ans;
    }
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int left = 0, right = n-1;
        int r1 = firstOcc(arr, n, x);
        if(r1 == -1)
            return {-1};
        return {r1, lastOcc(arr, n, r1, x)};
        // return {firstOcc(arr, n, x), lastOcc(arr, n, x)};
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends