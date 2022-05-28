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
        vector<int> leftBiggest(n), rightBiggest(n);
        leftBiggest[0] = 0;
        for(int i = 1; i < n; i++)
        {
            leftBiggest[i] = max(leftBiggest[i-1], arr[i-1]);
        }
        rightBiggest[n-1] = 0;
        for(int i = n-2; i >= 0; i--)
        {
            rightBiggest[i] = max(rightBiggest[i+1], arr[i+1]);
        }
        // for(int i = 0; i < n; i++)
        //     cout<<rightBiggest[i]<<" ";
        // cout<<endl;
        for(int i = 0; i < n; i++)
        {
            ll ht = (min(leftBiggest[i], rightBiggest[i]));
            ll water = ht - arr[i];
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