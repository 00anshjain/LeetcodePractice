// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
	public:
		int characterReplacement(string s, int k){
		int n = s.size();
        int j = 0, longest = 0;
        int res = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            longest = max(longest, mp[s[i]]);
            if(i - j + 1 - longest > k)
                mp[s[j++]]--;
            res = max(res, i - j + 1);
        }
        return res;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends