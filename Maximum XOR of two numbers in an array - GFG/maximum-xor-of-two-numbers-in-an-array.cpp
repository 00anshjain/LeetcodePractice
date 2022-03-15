// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int max_xor(int arr[], int n)
    {
       int maxx = 0, mask = 0;
        for(int i = 30; i >= 0; i--)
        {
            mask |= (1<<i);
            unordered_set<int> st;
            for(int j = 0; j < n; j++)
            {
                int x = arr[j];
                st.insert(x & mask);
            }
            int newMax = maxx | (1<<i);
            for(auto x : st)
            {
                // int x = arr[j];
                if(st.find(x^newMax) != st.end())
                {
                    maxx = newMax;
                    break;
                }
            }
        }
        return maxx;
    }
    
};


// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}


  // } Driver Code Ends