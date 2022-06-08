// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    typedef long long ll;
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        // return min(a[m-1] - a[0], a[n-1] - a[n-1-m]);
        int i = 0,j = m-1;
        ll diff = LONG_MAX;
        while(j < n)
        {
            diff = min(a[j++] - a[i++], diff);
        }
        return diff;
    }
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends