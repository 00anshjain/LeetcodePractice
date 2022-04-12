// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
	public:
		int characterReplacement(string s, int k){
		    int n = s.size();
        vector<int> j(26, 0);
        vector<int> cnt(26, 0);
        // int ja = 0, jb = 0;
        // int cnta = 0, cntb = 0;
        vector<int> sz(26, 0);
        int mx = 0;//, asize = 0, bsize = 0;
        for(int i = 0; i < n; i++)
        {
            for(int ch = 0; ch < 26; ch++)
            {
                sz[ch]++;
                if(s[i] - 'A' != ch)
                    cnt[ch]++;
                while(cnt[ch] > k)
                {
                    if(s[j[ch]] - 'A' != ch)
                        cnt[ch]--;
                    j[ch]++;
                    sz[ch]--;
                }
                mx = max(mx, sz[ch]);
            }
        }
        //     if(s[i] !='B')
        //     // {
        //         cntb++;
        //     // }
        //     if(s[i] != 'A')
        //         cnta++;
        //     while(cnta > k)
        //     {
        //         if(s[ja] != 'A')
        //         {
        //             cnta--;
        //         }
        //         ja++;
        //         asize--;
        //         // ja++;
        //     }
        //     while(cntb > k)
        //     {
        //         if(s[jb] != 'B')
        //         {
        //             cntb--;
        //         }
        //         jb++;
        //         bsize--;
        //         // ja++;
        //     }
        //     mx = max(asize, mx);
        //     mx = max(bsize, mx);
        // }
        return mx;
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