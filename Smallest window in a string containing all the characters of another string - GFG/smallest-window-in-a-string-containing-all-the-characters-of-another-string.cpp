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
        int n = s.size();
        unordered_map<char, int> mp;
        for(auto c : p)
            mp[c]++;
        int unq = mp.size();
        int i = 0, ans = n+1;
        int matched = 0;
        int start = 0;
        for(int j = 0; j < n; j++)
        {
            if(mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                {    
                    matched++;
                    while(matched == unq)
                    {
                        if(ans > j - i + 1)
                        {
                            ans = j-i+1;
                            start = i;
                        }
                        if(mp.find(s[i]) != mp.end())
                        {
                            mp[s[i]]++;
                            if(mp[s[i]] > 0)
                                matched--;
                        }
                        i++;
                    }
                }    
            }
        }
        if(ans > n)
            return "-1";
        return s.substr(start, ans);
        // Your code here
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