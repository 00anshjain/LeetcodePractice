// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool recur(int a[], int n, int k, int s, vector<int> &sum)
    {
        if(n == 0)
        {
            for(int i = 0; i < k; i++)
            {
                if(sum[i] != s)
                    return false;
            }
            return true;
        }
            
        for(int i = 0; i < k; i++)
        {
            if(sum[i] + a[n-1] <= s)
            {
                sum[i] += a[n-1];
                if(recur(a, n-1, k, s, sum))
                    return true;
                sum[i] -= a[n-1];
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int s = accumulate(a, a+n, 0);
        if(s%k != 0)
            return false;
        vector<int> sum(k, 0);
        return recur(a, n, k, s/k, sum);
         //Your code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends