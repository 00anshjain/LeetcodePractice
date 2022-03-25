// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int xDir[4] = {0, 1, 0, -1};
    int yDir[4] = {1, 0, -1, 0};
    char dir[4] = {'R', 'D', 'L', 'U'};
    bool isSafe(int row, int col, vector<vector<int>> &m, int n)
    {
        if(row < 0 || col < 0 || row >= n || col >= n || m[row][col] == 0 || m[row][col] == -1)
            return false;
        return true;
    }
    void helper(vector<vector<int>> &m, int n, vector<string> &ans, string curr, int row, int col)
    {
        if(row == n-1 && col == n-1)
        {
            // return curr;
            ans.push_back(curr);
            return;
        }
        m[row][col] = -1;
        for(int i = 0; i < 4; i++)
        {
            if(isSafe(row + xDir[i], col + yDir[i], m, n))
            {
                string temp = curr;
                temp += dir[i];
                helper(m, n, ans, temp, row + xDir[i], col + yDir[i]);
            }
        }
        m[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string curr = "";
        int row = 0, col = 0;
        if(m[0][0] == 0)
            return ans;
        if(m[n-1][n-1] == 0)
            return ans;
        helper(m, n, ans, curr, row, col);
        return ans;
        // Your code goes here
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends