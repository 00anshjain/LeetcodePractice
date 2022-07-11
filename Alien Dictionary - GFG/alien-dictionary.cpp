// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string arr[], int n, int k) {
        // unordered_map<char, int> mp;
        // for(int i = 'a'; i <= 'a' + k; i++)
        //     mp[i] = a-'a';
        vector<int> indegree(k, 0);
        vector<int> adj[k];
        for(int i = 0; i < n-1; i++)
        {
            int j = i+1;
            
            // for(int j = i+1; j < n; j++)
            // {
                string w1 = arr[i];
                string w2 = arr[j];
                int itr1=0, itr2=0;
                while(itr1 < w1.size() && itr2 < w2.size() && w1[itr1] == w2[itr2])
                {
                    itr1++;
                    itr2++;
                }
                if(itr1 >= w1.size() || itr2 >= w2.size())
                    continue;
                    
                indegree[w2[itr2] - 'a']++;
                adj[w1[itr1] - 'a'].push_back(w2[itr2] - 'a');
            // }
        }
        string ans = "";
        queue<int> q;
        for(int i = 0; i < k; i++)
        {
            if(indegree[i] == 0)
            {
                // ans.push_back(i = 'a');
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int t = q.front();
            ans += (t + 'a');
            q.pop();
            for(auto x : adj[t])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        // cout<<ans<<endl;
        return ans;
        //code here
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends