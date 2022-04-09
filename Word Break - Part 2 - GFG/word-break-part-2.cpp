// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void helper(unordered_set<string> &st, string str, string &s, int k, vector<string> &res, int sz)
    {
        if(k == sz)
        {
            res.push_back(str);
            return;
        }
        for(int i = k; i<s.size(); i++)
        {
            string b = s.substr(k, i-k+1);
            if(st.find(b) != st.end())
            {
                if(k == 0)
                    helper(st, str+b, s, i+1, res, sz);
                else
                    helper(st, str+" "+b, s, i+1, res, sz);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> res;
        string str = "";
        int sz = s.size();
        unordered_set<string> st(dict.begin(), dict.end());
        helper(st, str, s, 0, res, sz);
        return res;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends