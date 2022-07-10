// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The functions which 
builds the segment tree */
void buildSeg(int *tree, int idx, int arr[], int l, int r)
{
    if(l == r)
    {    tree[idx] = arr[l];
        return;
    }
    int mid = l + (r - l)/2;
    buildSeg(tree, 2*idx+1, arr, l, mid);
    buildSeg(tree, 2*idx+2, arr, mid+1, r);
    tree[idx] = min(tree[2*idx+1], tree[2*idx+2]);
        // return arr[l];
}
int *constructST(int arr[],int n)
{
    int *tree = new int[4*n];
    for(int i = 0; i < n; i++)
        tree[i] = INT_MAX;
    // memset(tree, INT_MAX, sizeof(tree));
    buildSeg(tree, 0, arr, 0, n-1);
    return tree;
  //Your code here
}

// we want answer between low index to high index
int findRMQ(int st[], int idx, int l, int r, int low, int high)
{
    if(l > high || r < low)
        return INT_MAX;
    if(l >= low && r <= high)
        return st[idx];
    int mid = (l+r)/2;
    int ans1 = findRMQ(st, 2*idx+1, l, mid, low, high);
    int ans2 = findRMQ(st, 2*idx+2, mid+1, r, low, high);
    return min(ans1, ans2);
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    return findRMQ(st, 0,  0, n-1, a, b);
//Your code here
}