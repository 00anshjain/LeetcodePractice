// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void combSum(vector<int>&A, int sum, int n, vector<vector<int>>& ans, vector<int>& v)
    {
        if(sum == 0)
        {
            ans.push_back(v);
            return;
        }
        if(n == 0)
            return;
        if(A[n-1] <= sum)
        {
            v.push_back(A[n-1]);
            combSum(A, sum - A[n-1], n, ans, v);
            v.pop_back();
        }
        combSum(A, sum, n-1, ans, v);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int> > ans;
        set<vector<int>> st;
        vector<int> v;
        set<int> s(A.begin(), A.end());
        vector<int> c(s.rbegin(), s.rend());
        // sort(A.begin(), A.end(), greater<int>());
        combSum(c, B, c.size(), ans, v);
        return ans;
        // Your code here
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends