// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N < M)
            return -1;
        if(N == M)
            return *max_element(A, A+N);
        int sum = A[0];
        int left = A[0];
        for(int i = 1; i < N; i++)
        {
            sum += A[i];
            left = max(left, A[i]);
        }
        int right = sum;
        int minPages= INT_MAX;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            // now we check if it works for us
            int currPages = 0;
            int students = 1;
            for(int i = 0; i < N; i++)
            {
                int x = A[i];
                if(x + currPages <= mid)
                    currPages += x;
                else
                {
                    currPages = x;
                    students++;
                    if(students > M)
                        break;
                }
            }
            if(students <= M)
            {
                minPages = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return minPages == INT_MAX ? -1 : minPages;
        //code here
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends