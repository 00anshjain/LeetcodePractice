// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    struct Node{
        int data;
        Node* left;
        Node* right;
        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n, -1);
        Node* head = NULL;
        head = new Node(arr[n-1]);
        Node* p = new Node(-1);
        for(int i = n-2; i >= 0; i--)
        {
            // if(!head)
            // {
            //     head = new Node(arr[i]);
            //     continue;
            // }
            Node* curr = head;
            Node* succ = p;
            while(1)
            {
                // Node* curr = head;
                if(curr->data > arr[i])
                {
                    succ = curr;
                    if(curr->left)
                        curr = curr->left;
                    else
                    {
                        curr->left = new Node(arr[i]);
                        // while(succ->right)
                        //     succ = succ->right;
                        ans[i] = succ->data;
                        break;
                    }
                }
                else if(curr->data < arr[i])
                {
                    if(curr->right)
                    {
                        curr = curr->right;
                    }
                    else
                    {
                        ans[i] = succ->data;
                        curr->right = new Node(arr[i]);
                        break;
                    }
                }
                else // curr->data == arr[i]
                {
                    if(curr->right)
                    {
                        succ = curr->right;
                        while(succ->left)
                            succ = succ->left;
                    }
                    ans[i] = succ->data;
                    break;
                }
            }
        }
        return ans;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}
  // } Driver Code Ends