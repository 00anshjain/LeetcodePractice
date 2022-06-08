// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sun = S/7;
        int canBuyDay = S - sun;
        int totalFoodReqd = M*S;
        int reqdBuyDay = ceil((double)totalFoodReqd/N);
        if(reqdBuyDay > canBuyDay)
            return -1;
        return reqdBuyDay;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends