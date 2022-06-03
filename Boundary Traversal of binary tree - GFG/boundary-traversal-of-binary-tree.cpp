// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void leftTraversal(Node* root, vector<Node*> &left)
    {
        if(!root)
            return;
        left.push_back(root);
        if(root->left)
            leftTraversal(root->left, left);
        else
            leftTraversal(root->right, left);
    }
    void rightTraversal(Node* root, vector<Node*> &right)
    {
        if(!root)
            return;
        right.push_back(root);
        if(root->right)
            rightTraversal(root->right, right);
        else
            rightTraversal(root->left, right);
    }
    void leafTraversal(Node* root, vector<Node*> &leafNodes)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            leafNodes.push_back(root);
            return;
        }
        if(root->left)
            leafTraversal(root->left, leafNodes);
        if(root->right)
            leafTraversal(root->right, leafNodes);
    
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root)
            return ans;
        vector<Node*> left;
        left.push_back(root);
        leftTraversal(root->left, left);
        vector<Node*> leafNodes;
        leafTraversal(root, leafNodes);
        vector<Node*> right;
        rightTraversal(root->right, right);
        reverse(right.begin(), right.end());
        // cout<<"left :";
        // for(auto x : left)
        //     cout<<x->data <<" ";
        // cout<<endl<<"leaf :";
        // for(auto x : leafNodes)
        //     cout<<x->data <<" ";
        // cout<<endl<<"righ :";
        // for(auto x : right)
        //     cout<<x->data <<" ";
        // cout<<endl;
        
        if(left.size() > 0 && leafNodes[0] == left[left.size() - 1])
            left.pop_back();
        if(right.size() > 0 && leafNodes.size() > 0 && leafNodes[leafNodes.size() - 1] == right[0])
            leafNodes.pop_back();
        for(Node* x : left)
            ans.push_back(x->data);
        for(Node* x : leafNodes)
            ans.push_back(x->data);
        for(Node* x : right)
            ans.push_back(x->data);
        return ans;
        //Your code here
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends