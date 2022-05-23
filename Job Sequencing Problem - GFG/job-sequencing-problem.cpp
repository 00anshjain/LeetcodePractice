// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job j1, Job j2)
    {
        return j1.profit > j2.profit;
    }
    int find(vector<int> &parent, int i)
    {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
    void union_gr(vector<int> &parent, int x, int y)
    {
        parent[x] = y;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        int mxTime = 0;
        for(int i = 0; i < n; i++)
            mxTime = max(mxTime, arr[i].dead);
        vector<int> parent(mxTime+1);
        for(int i = 1; i <= mxTime; i++)
        {
            parent[i] = i;
        }
        vector<int> res(mxTime+1, -1);
        for(int i = 0; i < n; i++)
        {
            int availSlot = find(parent, arr[i].dead);
            if(availSlot > 0)
            {
                parent[availSlot] = availSlot-1;
                res[availSlot] = i;
            }
        }
        int cnt = 0;
        int pro = 0;
        for(int i = 1; i<= mxTime; i++)
        {
            if(res[i] != -1)
            {
                cnt++;
                pro += arr[res[i]].profit;
            }
        }
        return {cnt, pro};
        // your code here
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends