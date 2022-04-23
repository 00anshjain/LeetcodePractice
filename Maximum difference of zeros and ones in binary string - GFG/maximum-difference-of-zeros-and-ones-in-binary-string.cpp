// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int cnt = 0;
	    int mx = INT_MIN;
	    int n = S.size();
	    for(int i = 0; i < n; i++)
	    {
	        if(S[i]=='0')
	        {
	            cnt++;
	           // if(mx < cnt)
	           //     mx = cnt;
	        }
	        else
	        {
	            cnt--;
	           // if(mx > cnt)
	           //     mx = cnt;
	           // if(cnt < 0)
	           //     cnt = 0;
	        }
	        mx = max(cnt, mx);
	        if(cnt<0)
	        cnt=0;
	    }
	    return mx;
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