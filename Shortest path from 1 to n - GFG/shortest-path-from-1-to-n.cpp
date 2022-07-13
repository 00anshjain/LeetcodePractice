// { Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        int cnt = 0;
        while(n > 1)
        {
            if(n <= 2)
                return cnt + n-1;
            if(n%3 == 0)
            {
                n/= 3;
                cnt++;
            }
            else
            {
                cnt += n%3;
                n -= n%3;
            }
        }
        return cnt;
        //complete the function here
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
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 

  // } Driver Code Ends