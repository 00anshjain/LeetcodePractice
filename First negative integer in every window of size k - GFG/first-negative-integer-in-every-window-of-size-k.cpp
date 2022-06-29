// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

typedef long long ll;
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
    
    queue<ll> q;
    for(ll i = 0; i < k-1; i++)
    {
        if(A[i] < 0)
            q.push(i);
    }
    ll i = 0;
    vector<ll> ans;
    for(ll j = k-1; j < N; j++)
    {
        if(A[j] < 0)
            q.push(j);
        if(!q.empty() && q.front() < i)
        {
            q.pop();
            // i++;
        }
        if(q.empty())
            ans.push_back(0);
        else
            ans.push_back(A[q.front()]);
        i++;
    }
    return ans;
 }