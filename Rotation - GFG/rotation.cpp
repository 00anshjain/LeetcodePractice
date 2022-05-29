// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int left = 0, right = n-1;
	    int mid;
	    while(left <= right)
	    {
	        if(arr[left] <= arr[right])
	        {
	            return left;
	        }
	        mid = left + (right- left)/2;
	        if(arr[mid] <= arr[(mid +1)%n] && arr[mid] <= arr[(mid -1+n)%n])
	            return mid;
	        if(arr[left]<= arr[mid])
	            left = mid+1;
	        else
	            right = mid -1;
	    }
	    return 0;
	    // code here
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends