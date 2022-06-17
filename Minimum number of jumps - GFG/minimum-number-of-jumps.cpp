// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int steps = 0;
        int mx = 0;
        int jump = 0;
        for(int i = 0; i < n; i++)
        {
            if(mx < i)
                return -1;
            if(i == n-1)
                return jump;
            mx = max(mx, arr[i] + i);
            if(steps == 0)
            {
                jump++;
                steps = mx - i;
            }
            steps--;
        }
        return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends