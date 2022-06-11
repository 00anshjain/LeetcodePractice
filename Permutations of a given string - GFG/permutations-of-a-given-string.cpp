// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void recur(string &s, vector<bool> &taken, int sz, string curr, int n, vector<string>& ans, unordered_set<string>& dict)
	    {
	        if(dict.find(curr) != dict.end())
	            return;
	        dict.insert(curr);
	        if(sz == n)
	        {
	            ans.push_back(curr);
	            return;
	        }
	        for(int i = 0; i < n; i++)
	        {
	            if(!taken[i])
	            {
	                taken[i] = true;
	                recur(s, taken, sz+1, curr + s[i], n, ans, dict);
	                taken[i] = false;
	            }
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    vector<string> ans;
		    sort(s.begin(), s.end());
		    int n = s.size();
		    vector<bool> taken(n, false);
		    unordered_set<string> dict;
		    recur(s, taken, 0, "", n, ans, dict);
		  //  vector<string> res(ans.begin(), ans.end())
		    return ans;
		    // Code here there
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends