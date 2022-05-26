// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int k = pat.size();
	    int n = txt.size();
	    int i = 0, j = 0;
	    unordered_map<char, int> patmp;
	    for(auto c : pat)
	        patmp[c]++;
	    unordered_map<char, int> txtmp;
	    int cnt = 0;
	    while(j < n)
	    {
	        if(j - i + 1 < k)
	        {
	            txtmp[txt[j]]++;
	        }
	        else
	        {
	            txtmp[txt[j]]++;
	            bool flag = false;
	            for(auto x : patmp)
	            {
	                if(txtmp[x.first] < x.second)
                   {
                       flag = true;
                       break;
                   }
	            }
	            if(!flag)
	            {
	                cnt++;
	            }
	            txtmp[txt[i]]--;
	            i++;
	        }
	        j++;
	    }
	    return cnt;
	    // code here
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends