// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char, int> mp;
        for(auto c : s)
            mp[c]++;
        priority_queue<int> pq;
        for(auto x : mp)
            pq.push(x.second);
        while(pq.top() != 0 && k-- > 0)
        {
            int a = pq.top();
            a--;
            pq.pop();
            pq.push(a);
        }
        int ans = 0;
        while(!pq.empty() && pq.top() != 0)
        {
            int a = pq.top();
            ans += (a*a);
            pq.pop();
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends