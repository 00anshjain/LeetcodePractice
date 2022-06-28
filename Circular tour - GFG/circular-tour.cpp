// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int k = n + n-1;
        int j = 0, i = 0;
        int pet = 0;
        while( j < k && i < n)
        {
            pet += (p[j%n].petrol - p[j%n].distance);
            while(pet < 0 && i < n)
            {
                pet -= (p[i].petrol - p[i].distance);
                i++;
            }
            if(j - i == n-1)
                return i;
            j++;
        }
        return -1;
        
       //Your code here
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends