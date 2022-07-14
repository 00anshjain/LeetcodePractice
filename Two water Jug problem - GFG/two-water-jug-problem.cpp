// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int gcd(int a, int b)
	{
	    if(b > a)
	        return gcd(b, a);
	    if(b == 0)
	        return a;
	    return gcd(b, a%b);
	}
	int fillWater(int to, int from, int d)
	{
	    int toCap = 0, fromCap = from;
	    int steps = 1;
	    while(toCap != d && fromCap != d)
	    {
	        int temp = min(to - toCap, fromCap);
	        toCap += temp;
	        fromCap -= temp;
	        steps++;
	        if(toCap == d || fromCap == d)
	            return steps;
	        if(fromCap == 0)
	        {
	            fromCap = from;
	            steps++;
	        }
	        if(toCap == to)
	        {
	            toCap = 0;
	            steps++;
	        }
	    }
	    return steps;
	}
	int minSteps(int m, int n, int d)
	{
	    //mx + ny = d
	    // only solution if =>
	    if(d == 0)
	        return 0;
	    if(d > max(n, m))
	        return -1;
	    if(d%gcd(m, n) != 0)
	        return -1;
	   return min(fillWater(n, m, d), fillWater(m, n, d));
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends