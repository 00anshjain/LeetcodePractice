// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    typedef long long ll;
    int minSubset(vector<int> &arr,int N){
        ll sum = accumulate(arr.begin(), arr.end(), 0ll);
        sum = (sum)/2;
        sort(arr.begin(), arr.end(), greater<int>());
        int i = 0;
        while (i < N && sum >= 0)
        {
            sum -= arr[i++];
        }
        return i;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends