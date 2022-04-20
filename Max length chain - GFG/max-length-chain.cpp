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
static bool comp(struct val v1, struct val v2)
{
    return v1.first < v2.first;
    // if(v1.first < v2.first)
        // return true;
        
    // else
    //     return v1.second <= v2.second;
}
int maxChainLen(struct val p[],int n)
{
    sort(p, p+n, comp);
    // for(int i = 1; i < n; i++)
    //     cout<<p[i].first<<" "<<p[i].second<<endl;
    long long int last = p[0].second;
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(p[i].first > last)
        {
            cnt++;
            last = p[i].second;
        }
        else
        {
            if(p[i].second < last)
                last = p[i].second;
        }
    }
    return cnt;
            //Your code here
}