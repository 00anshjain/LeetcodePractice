// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // code here
        list<int> q;
        unordered_map<int,list<int>::iterator >mp;
        int i = 0; 
        int pagefault = 0;
        while(i < n)
        {
            if(mp.find(pages[i]) == mp.end() )
            {
                if(q.size() < c)
                {
                    q.push_back(pages[i]);
                    auto itr = q.end();
                    itr--;
                    mp[pages[i]] = itr;
                }
                else
                {
                    int a = q.front();
                    mp.erase(a);
                    q.pop_front();
                    q.push_back(pages[i]);
                    auto itr = q.end();
                    itr--;
                    mp[pages[i]] = itr;
                }
                pagefault++;
            }
            else
            {
                q.erase(mp[pages[i]]);
                q.push_back(pages[i]);
                auto itr = q.end();
                itr--;
                mp[pages[i]] = itr;
            }
            i++;
        }
        return pagefault;
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