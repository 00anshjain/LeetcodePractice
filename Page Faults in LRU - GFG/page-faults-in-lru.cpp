// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_map<int, int> mp;
        int fault = 0;
        for(int i =0; i < N; i++)
        {
            if(mp.find(pages[i]) == mp.end())
            {
                fault++;
                if(mp.size() < C)
                {
                    mp[pages[i]] = i;
                }
                else
                {
                    int lastUsed = INT_MAX;
                    // int pageNo = 0;
                    auto pageToRemove = mp.begin();
                    for(auto itr = mp.begin(); itr != mp.end(); itr++)
                    {
                        if(itr->second < lastUsed)
                        {
                            lastUsed = itr->second;
                            pageToRemove = itr;
                        }
                    }
                    mp.erase(pageToRemove);
                    mp[pages[i]] = i;
                }
            }
            else
            {
                mp[pages[i]] = i;
            }
        }
        return fault;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends