// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int sz1 = 0, sz2 = 0;
    void insertHeap(int &x)
    {
        if(sz1 == sz2)
        {
            pq1.push(x);
            pq2.push(pq1.top());
            pq1.pop();
            pq1.push(pq2.top());
            pq2.pop();
            sz1++;
        }
        else
        {
            pq1.push(x);
            pq2.push(pq1.top());
            pq1.pop();
            sz2++;
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        return;
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(sz1 == sz2)
            return ((double)pq1.top() + pq2.top())/2.0;
        return pq1.top();
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends