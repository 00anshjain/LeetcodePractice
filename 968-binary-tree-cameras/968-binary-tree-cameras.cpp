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
    // 2 -> camera lagaya h
    // 1 -> covered from below
    // 0 -> emergency not covered from below now need one from above
    int camera = 0;
    int minCameraCoverUtil(TreeNode* root)
    {
        if(!root)
            return 1;
        int l = minCameraCoverUtil(root->left);
        int r = minCameraCoverUtil(root->right);
        if(l == 0 || r == 0)
        {
            camera++;
            return 2;
        }   
        if(l == 2 || r == 2)
            return 1;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(minCameraCoverUtil(root) == 0)
            return camera + 1;
        return camera;
        
    }
};