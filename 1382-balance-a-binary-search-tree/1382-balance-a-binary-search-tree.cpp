/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    typedef TreeNode Node;
    void inOrder(Node* root, vector<int> &arr)
    {
        if(!root)
            return;
        if(root->left)
            inOrder(root->left, arr);
        arr.push_back(root->val);
        if(root->right)
            inOrder(root->right, arr);
    }
    Node* helper(vector<int> &arr, int l, int r)
    {
        if(l > r)
            return NULL;
        int mid = l + (r-l)/2;
        Node* root = new Node(arr[mid]);
        root->left = helper(arr, l, mid - 1);
        root->right = helper(arr, mid+1, r);
        return root;

    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inOrder(root, arr);
        int n = arr.size();
        return helper(arr, 0, n-1);
    }
};