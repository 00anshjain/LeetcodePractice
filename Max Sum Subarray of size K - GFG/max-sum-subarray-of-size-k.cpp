// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long long maximumSumSubarray(int K, vector<int> &arr , int N){
        long long i = 0, j = 0;
        long long sum = 0;
        while(j - i + 1 <= K)
        {
            sum += arr[j++];
        }
        long long mxSum = sum;
        while(j < N)
        {
            sum += arr[j++];
            sum -= arr[i++];
            mxSum = max(mxSum, sum);

        }
        return mxSum;
        // code here 
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends