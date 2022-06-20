// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    int sz;
	    void recur(unordered_set<string> &st, string &curr, string &S, vector<string> &ans, int n)
	    {
	        if(st.find(curr) != st.end())
	            return;
	        st.insert(curr);
	        if(n == 0)
	        {
	            ans.push_back(curr);
	            return;
	        }
	        for(int i = 0; i < sz; i++)
	        {
	            if(S[i] != '&')
	            {
	                char k = S[i];
	                curr.push_back(k);
	                S[i] = '&';
	                recur(st, curr, S, ans, n-1);
	                curr.pop_back();
	                S[i] = k;
	            }
	        }
	    }
		vector<string> find_permutation(string S)
		{
		  //  sort(S.begin(), S.end());
		    unordered_set<string> st;
		    string curr = "";
		    vector<string> ans;
		    int n = S.size();
		    sz = n;
		    recur(st, curr, S, ans, n);
		    sort(ans.begin(), ans.end());
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