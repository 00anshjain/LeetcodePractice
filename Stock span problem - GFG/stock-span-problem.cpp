// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int prices[], int n)
    {
        vector<int> ans(n);
        ans[0] = 1;
        stack<pair<int, int>> st;
        st.push({prices[0], 0});
        for(int i = 1; i < n; i++)
        {
            ans[i] = 1;
            // if(prices[i] >= prices[i-1])
            {
                while(!st.empty() && st.top().first <= prices[i])
                {
                    ans[i] += ans[st.top().second];
                    st.pop();
                }
                // ans[i] = ans[i-1]+1;
                // st.pop();
                // while(!st.empty() && st.top() <= prices[i])
                // {
                //     ans[i] += 1;
                //     st.pop();
                // }
            }
            st.push({prices[i], i});
        }
        return ans;
       // Your code here
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends