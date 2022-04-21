// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
static bool comp(struct val a, struct val b)
{
    // if(a.first == b.first)
    //     return a.second < b.second;
    return a.first < b.first;
}
int maxChainLen(struct val p[],int n)
{
    sort(p, p+n, comp);
    vector<int> dp(n, 1);
    int mx=0;
    for(int i = n-1; i>= 0; i--)
    {
        for(int j = i+1; j< n; j++)
        {
            if(p[i].second < p[j].first)
            {
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        mx = max(dp[i], mx);
    }
    return mx;
//Your code here
}