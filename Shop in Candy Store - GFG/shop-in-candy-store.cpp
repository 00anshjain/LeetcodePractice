// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int getCandies(int candies[], int n, int k)
    {
        int i = 0, j = n-1;
        int price = 0;
        while(i<=j)
        {
            price += candies[i];
            j -= k;
            i++;
        }
        return price;
    }
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies+N);
        int c1 = getCandies(candies, N, K);
        reverse(candies, candies+N);
        int c2 = getCandies(candies, N, K);
        return {c1, c2};
        // Write Your Code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends