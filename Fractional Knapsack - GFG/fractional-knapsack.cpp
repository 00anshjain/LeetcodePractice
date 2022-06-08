// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool compare(Item &I1, Item &I2)
    {
        return I1.value/(double)I1.weight > I2.value/(double)I2.weight;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, compare);
        double pro = 0;
        int i = 0;
        while(W > 0 && i < n)
        {
            if(W >= arr[i].weight)
            {
                W -= arr[i].weight;
                pro += arr[i].value;
            }
            else
            {
                pro += ((double)arr[i].value/arr[i].weight) * W;
                W = 0;
            }
            i++;
        }
        return pro;
        
        // Your code here
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends