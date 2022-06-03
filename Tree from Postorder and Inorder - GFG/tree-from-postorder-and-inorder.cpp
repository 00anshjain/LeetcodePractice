// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* recur(int in[], int post[], int leftIn, int rightIn, int leftPost, int rightPost)
{
    if(leftIn > rightIn)
        return NULL;
    Node* curr = new Node(post[rightPost]);
    if(leftIn == rightIn)
        return curr;
    int idx = find(in+leftIn, in + rightIn +1, curr->data) - in;
    curr->left = recur(in, post, leftIn, idx - 1, leftPost, leftPost+(idx-1 - leftIn));
    curr->right = recur(in, post, idx + 1, rightIn, leftPost+(idx-1 - leftIn)+1, rightPost - 1);
}
Node *buildTree(int in[], int post[], int n) {
    return recur(in, post, 0, n-1, 0, n-1);
    
    // Your code here
}
