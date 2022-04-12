// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char, int> mp;
        // unordered_set<char> st;
        for(auto c : p)
        {
            mp[c]++;
            // st.insert(c);
        }
        int n = s.size();
        int k = p.size();
        if(k > n)
            return "-1";
        string ans = "-1";
        int ans_sz = INT_MAX;
        int j = 0;
        int matched = 0;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                mp[s[i]]--;
                if(mp[s[i]]>= 0)
                    matched++;
                while(matched == k)
                {
                    // ans = min(ans, i-j+1);
                    if(i-j+1 < ans_sz)
                    {
                        ans_sz = i-j+1;
                        ans = s.substr(j, i-j+1);
                    }
                    // j++;
                    if(mp.find(s[j]) != mp.end())
                    {
                        mp[s[j]]++;
                        if(mp[s[j]] > 0)
                            matched--;
                    }
                    j++;
                }
            }
        }
        // if(ans == INT_MAX)
        //     return "-1";
        return ans; 
        
        
        
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends