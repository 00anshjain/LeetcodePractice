// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int d){
        // code here 
        if(S > d*9)
            return "-1";
        // if(d == 1)
        //     return to_string(S);
        string ans = "";
        while(S > 9)
        {
            ans += '9';
            d--;
            S-= 9;
        }
        if(d == 1)
        {
            ans += to_string(S);
            d--;
        }
        else if(d > 1)
        {
            ans += to_string(S-1);
            d--;
            while(d != 1)
            {
                ans += '0';
                d--;
            }
            ans += '1';
        }
        else
            return "-1";
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends