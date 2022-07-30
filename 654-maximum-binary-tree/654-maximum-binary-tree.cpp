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
    TreeNode* recur(vector<int> &nums, int l, int r)
    {
        if(r < l)
            return NULL;
        if(r == l)
            return new TreeNode(nums[l]);
        int mx = nums[l], idx = l;
        int k = l;
        while(k <= r)
        {
            if(nums[k] > mx)
            {
                mx = nums[k];
                idx = k;
            }
            k++;
        }
        TreeNode* root = new TreeNode(mx);
        root->left = recur(nums, l, idx-1);
        root->right = recur(nums, idx+1, r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recur(nums, 0, nums.size() - 1);
    }
};