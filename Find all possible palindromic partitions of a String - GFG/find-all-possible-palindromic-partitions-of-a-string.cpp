// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int n;
    bool isPalin(string &s)
    {
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void recur(string &s, string curr, vector<string> ans, vector<vector<string>> &res, int i)
    {
        if(i == n)
        {
            if(curr == "")
            {
                res.push_back(ans);
            }
            return;
        }
        curr += s[i];
        recur(s, curr, ans, res, i+1);
        if(isPalin(curr))
        {
            ans.push_back(curr);
            curr = "";
            recur(s, curr, ans, res, i+1);
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        n = S.size();
        string curr = "";
        vector<vector<string>> res;
        vector<string> ans;
        recur(S, curr, ans, res, 0);
        sort(res.begin(), res.end());
        return res;
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends