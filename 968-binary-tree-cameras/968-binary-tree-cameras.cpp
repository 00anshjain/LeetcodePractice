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
    int camera = 0;
    // where we put camera we return 0;
    // if no camera but covered from below return 1;
    // if no camera but needed to be covered by up return 2. so if child return 2 we need to put camera here
    int cam(TreeNode* root)
    {
        if(!root)
            return 1;
        if(!root->left && !root->right)
            return 2;
        int l = cam(root->left);
        int r = cam(root->right);
        if(l == 2 || r == 2)
        {
            camera++;
            return 0;
        }
        if(l == 0 || r == 0)
            return 1;
        if(l == 1 ||r == 1)
            return 2;
        return 1;
    }
    int minCameraCover(TreeNode* root) {
        int k = cam(root);
        if(k == 2)
            return camera+1;
        return max(1,camera);
        // 1 for when theres only one node, with no children so we return 1 in that case
    }
};