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
    return a.second < b.second;
}
int maxChainLen(struct val p[],int n)
{
    vector<int> dp(n, 1);
    sort(p, p+n, comp);
    // memset(dp, 1, sizeof(dp));
    // dp[0] = 1;
    int mx = 0;
    int t= INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(p[i].first > t)
        {
            t = p[i].second;
            mx++;
        }
    }
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = i-1; j >= 0; j--)
    //     {
    //         if(p[j].second < p[i].first)
    //         {
    //             dp[i] = max(dp[i], dp[j] + 1);
    //         }
            
    //     }
    //     mx = max(mx, dp[i]);
    // }
    // for(int i = 0; i < n; i++)
    //     cout<<dp[i]<<" ";
    return mx;
//Your code here
}