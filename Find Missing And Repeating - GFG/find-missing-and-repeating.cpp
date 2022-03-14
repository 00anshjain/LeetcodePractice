// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int xorr = 0;
        for(int i = 0; i < n; i++)
        {
            xorr ^= arr[i];
            xorr ^= (i+1);
        }
        int RSB = (xorr & -xorr);
        int num1 = 0, num2 = 0;
        for(int i = 0; i < n; i++)
        {
            if((RSB & arr[i]) > 0)
            {
                num1 ^= arr[i];
            }
            else
            { 
                num2 ^= arr[i];
            }
            if((RSB & (i+1)) > 0)
            {
                num1 ^= (i+1);
            }
            else
            {
                num2 ^= (i+1);
            }
        }
        // int miss, dup;
        int* ans = new int[2];
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == num1)
            {
                // dup = num1;
                // miss = num2;
                ans[0] = num1;
                ans[1] = num2;
                break;
            }
            else if(arr[i] == num2)
            {
                // dup = num2;
                // miss = num1;
                ans[0] = num2;
                ans[1] = num1;
                break;
            }
        }
        // arr[0] = num1;
        // arr[1] = num2;
        // ans[0] = num2;
        // ans[1] = num1;
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends