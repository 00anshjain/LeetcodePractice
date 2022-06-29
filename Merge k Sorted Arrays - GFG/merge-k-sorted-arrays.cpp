// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    struct comp{
        bool operator()(vector<int>& v1, vector<int>& v2)
        {
            return v1.size() > v2.size();
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq(arr.begin(), arr.end());
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            if(pq.empty())
                return t;
            auto s = pq.top();
            pq.pop();
            int n1 = t.size(), n2 = s.size();
            int i = 0, j = 0;
            // int k = 0;
            vector<int> ans;
            while(i < n1 && j < n2)
            {
                if(t[i] < s[j])
                    ans.push_back(t[i++]);
                else
                    ans.push_back(s[j++]);
            }
            while(i < n1)
                ans.push_back(t[i++]);
            while(j < n2)
                ans.push_back(s[j++]);
            pq.push(ans);
        }
        return {};
        
        //code here
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends