// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    typedef long long ll;
    long long minCost(long long arr[], long long n) {
        priority_queue<ll, vector<ll>, greater<ll>> pq(arr, arr+n);
        ll sum = 0;
        if(n == 1)
            return 0;
        while(pq.size() != 1)
        {
            ll t1 = pq.top();
            pq.pop();
            ll t2 = pq.top();
            pq.pop();
            pq.push(t1+t2);
            sum += t1+t2;
        }
        return sum;
        
        // Your code here
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends