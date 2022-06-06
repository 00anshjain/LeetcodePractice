// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        
        map<int, deque<int>> Amap, Bmap;
        for(int i = 0;i < 2*e; i += 2)
        {
            Amap[A[i]].push_back(A[i+1]);
            Bmap[B[i]].push_back(B[i+1]);
        }
        // for(auto a : mp.begin())
        if(Amap.size() != Bmap.size())
            return 0;
        auto itr1 = Amap.begin();
        // auto itr2 = Bmap.begin();
        // while(itr1 != Amap.end() && itr2 != Bmap.end())
        while(itr1 != Amap.end())
        {
            auto q1 = itr1->second;
            auto q2 = Bmap[itr1->first];
            int n1 = q1.size(), n2 = q2.size();
            if(n1 != n2)
                return false;
            while(n1-- > 0)
            {
                if(q1.front() != q2.back())
                    return false;
                q1.pop_front();
                q2.pop_back();
                
            }
            itr1++;
            // itr2++;
        }
        return true;
            
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends