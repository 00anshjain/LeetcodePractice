// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        
        int l = 2*i + 1;
        // if( l >= n)
        //     return;
        int r = 2*i+2;
        // if(r >= n)
        //     r = -1;
        int largest = i;
        if(l < n && arr[i] < arr[l])
            largest = l;
        if(r < n && arr[largest] < arr[r])
            largest = r;
        if(largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }    
      // Your Code Here
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        int l = (n-1)/2;
        while(l >= 0)
        {
            heapify(arr, n, l);
            l--;
        }
        
        
        
    // Your Code Here
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        while(n > 0)
        {
            swap(arr[0], arr[n-1]);
            heapify(arr, n-1, 0);
            
            n--;
        }
        // reverse(arr, arr+n);
        //code here
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends