// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    int zero = 0, one = 0, ans = INT_MIN;
	    for(char c : s)
	    {
	        if(c == '0')
	        {
	            zero++;
	           // one++;
	        }
	        else
	        {
	            one++;
	           // zero--;
	        }
    	    ans = max(ans, zero - one);
    	    if(one > zero)
    	    {
    	        one = 0;
    	        zero = 0;
	        }
    	   // if(zero < 0)
    	   //     zero = 0;
	    }
	    return ans;
	    // Your code goes here
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends