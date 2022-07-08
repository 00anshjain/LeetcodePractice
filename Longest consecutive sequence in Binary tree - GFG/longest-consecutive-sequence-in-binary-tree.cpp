// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
struct Node
{
	int data;
	Node *left, *right;
};
*/
class Solution{
  public:
    // your task is tp complete this function
    // function should return the length of the longestConsecutive
    // sequence
    int recur(Node* root)
    {
        int ans = 1;
        // if(t == 1)
        // {
            if(root->left && root->left->data == root->data + 1)
                ans = max(ans, 1+recur(root->left));
            if(root->right && root->right->data == root->data + 1)
                ans = max(ans, 1+ recur(root->right));
        // }
        // else
        // {
            // if(root->left && root->left->data == root->data - 1)
            //     ans = max(ans, 1 + recur(root->left, t));
            // if(root->right && root->right->data == root->data -1)
            //     ans = max(ans, 1 + recur(root->right, t));
        // }
        return ans;
    }
    int longestConsecutive(Node* root)
    {
        // int ans = 0;
        if(!root)
            return -1;
        // int t = 0, t2 = 1;// t= 0 means no flow, t = 1 means
        int ans = recur(root);
        
        if(root->left)
            ans = max(ans, longestConsecutive(root->left));
        if(root->right)
            ans = max(ans, longestConsecutive(root->right));
        if(ans == 1)
            return -1;
        return ans;
         //Code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        cout<<obj.longestConsecutive(root)<<endl;
    }
    return 0;
}
  // } Driver Code Ends