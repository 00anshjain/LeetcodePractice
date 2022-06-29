// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
typedef vector<int> vi;
class Solution{
    public:
    struct element{
        int num;
        int i;
        int j;
        // int n;
        element(int a, int b, int c)
        {
            num = a;
            i = b;
            j = c;
            // n = d;
        }
    };
    struct compare{
      bool operator()(element a, element b)
      {
          return a.num > b.num;
      }
    };
    
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        // int k = arr.size();
        // int n = arr[0].size();
        priority_queue<element, vector<element>, compare> pq;
        int mx = INT_MIN;
        int len = INT_MAX;
        vector<int> pr;
        for(int j = 0; j < k; j++)
        {
            pq.push(element(arr[j][0], j, 0));
            mx = max(mx, arr[j][0]);
        }
        while(!pq.empty())
        {
            element v = pq.top();
            pq.pop();
            int num = v.num;
            int i = v.i;
            int j = v.j;
            // int n = v.n;
            if(len > mx - num)
            {
                len = mx - num;
                pr = {num, mx};
                // cout<<pr[0]<<" "<<pr[1]<<" "<<j<<" "<<n-1<<endl;
            }
            if(j == n-1)
                break;
            pq.push(element(arr[i][j+1], i, j+1));
            if(arr[i][j+1] > mx)
                mx = arr[i][j+1];
        }
        pair<int, int> ans = make_pair(pr[0], pr[1]);
        return ans;
        
          //code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends