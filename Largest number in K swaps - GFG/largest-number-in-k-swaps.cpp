// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void recur(string &str, string &g, string &ans, int n, int k, int i)
    {
        if(k == 0 || i == n)
        {
            ans = max(ans, str);
            return;
        }
        // while( i < n && k >= 0)
        // {
            if(str[i] != g[i])
            {
                for(int j = n-1; j > i; j--)
                {
                    if(g[i] == str[j])
                    {
                        swap(str[j], str[i]);
                        // k--;
                        recur(str, g, ans, n, k-1, i+1);
                        swap(str[j], str[i]);
                        // break;
                    }
                }
            }
            else
            {
                recur(str, g, ans, n, k, i+1);
            }
            // i++;
        // }
    }
    string findMaximumNum(string str, int k)
    {
        string g = str;
        string ans = str;
        sort(g.begin(), g.end(), greater<char>());
        int n = str.size();
        int i  = 0;
        recur(str, g, ans, n, k, i);
        return ans;
       // code here.
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends