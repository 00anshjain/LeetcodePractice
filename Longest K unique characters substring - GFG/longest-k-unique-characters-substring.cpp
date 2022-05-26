// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> mp;
        int ans = -1;
        int n = s.size();
        int unq = 0;
        int i = 0;
        for(int j = 0; j < n; j++)
        {
            // if(unq < k)
            // {
                mp[s[j]]++;
                if(mp[s[j]] == 1)
                    unq += 1;
                // j++;
            // }
            while(unq > k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    unq -= 1;
                i++;
            }
            if(unq == k)
            {
                ans = max(ans, j-i+1);
                // cout<<j<<" "<<i<<" "<<unq<<endl;
            }
        }
        return ans;
    // your code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends