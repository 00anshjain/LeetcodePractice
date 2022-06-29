// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        for(int i = 1; i < n; i++)
            arr[i] += arr[i-1];
        priority_queue<int> pq;
        for(int i = -1; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(i != -1)
                    pq.push(arr[j] - arr[i]);
                else
                    pq.push(arr[j]);
            }
        }
        while(k-- > 1)
            pq.pop();
        return pq.top();
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends