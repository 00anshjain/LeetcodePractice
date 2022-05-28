// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPossible(int t, int S1, int S2, int N)
    {
        if(((long long)t/S1 + (long long)t/S2) >= (long long)N)
            return true;
        return false;
    }
    int minTime(int S1, int S2, int N){
        int right = INT_MAX - 10000;
        int left = 1;
        int ans = -1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(isPossible(mid, S1, S2, N))
            {
                // cout<<"mid = "<<mid<<endl;
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S1, S2, N;
        cin>>S1>>S2>>N;
        
        Solution ob;
        cout<<ob.minTime(S1, S2, N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends