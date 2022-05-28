// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    typedef long long ll;
    long long trappingWater(int arr[], int n){
        ll ans = 0;
        if(n <= 2)
            return 0;
        vector<int> maxL(n), maxR(n);
        maxL[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            maxL[i] = max(maxL[i-1], arr[i]);
        }
        maxR[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            maxR[i] = max(maxR[i+1], arr[i]);
        }
        // for(int i = 0; i < n; i++)
        //     cout<<maxR[i]<<" ";
        // cout<<endl;
        for(int i = 0; i < n; i++)
        {
            ll water = min(maxL[i], maxR[i]) - arr[i];
            if(water > 0)
                ans += water;
            // cout<<ht<<endl;
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends