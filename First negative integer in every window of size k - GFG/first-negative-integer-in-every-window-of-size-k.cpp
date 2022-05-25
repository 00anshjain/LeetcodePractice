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



vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int K) {
    long long i = 0, j = 0;
    vector<long long> res;
    queue<long long> q;
    while(j < n)
    {
        // cout<<"HI"<<endl;
        if(j - i + 1 < K)
        {
            if(arr[j] < 0)
                q.push(arr[j]);
            // j++;
        }
        else
        {
            if(arr[j] < 0)
                q.push(arr[j]);
            if(q.empty())
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(q.front());
                if(arr[i] == q.front())
                    q.pop();
            }
            i++;
        }
        j++;
    }
    return res;
                                                 
 }