// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i)
    {
        int l = 2*i+1;
        int r = 2*i+2;
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
    }
    void buildHeap(vector<int> &arr, int n)
    {
        // cout<<"n = "<<n<<endl;
        // n--;
        int k = (n-1)/2;
        for(int i = k; i >= 0; i--)
            heapify(arr, n, i);
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> arr(n+m);
        for(int i = 0; i < n; i++)
            arr[i] = a[i];
        for(int j = 0; j < m;j++)
            arr[j+n] = b[j];
        buildHeap(arr, m+n);
        // for(int i = 0; i < m+n; i++)
        //     cout<<arr[i]<<" ";
        return arr;
        // your code here
    }
};

// { Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
  // } Driver Code Ends