// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void DFS(int u, vector<bool> &visited, string &ans, vector<int> adj[])
    {
        visited[u] = true;
        for(auto x : adj[u])
        {
            if(!visited[x])
                DFS(x, visited, ans, adj);
        }
        char ch = u+'a';
        ans = ch + ans;
        
    }
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i = 0; i < N-1; i++)
        {
            string w = dict[i];
            string s = dict[i+1];
            for(int j = 0; j < min(w.size(), s.size()); j++)
            {
                if(w[j] != s[j])
                {
                    adj[w[j]-'a'].push_back(s[j]-'a');
                    break;
                }
            }
        }
        // now we apply topo sort
        // stack<int> st;
        vector<bool> visited(K, false);
        string ans = "";
        for(int i = 0; i < K; i++)
        {
            if(!visited[i])
                DFS(i, visited, ans, adj);
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