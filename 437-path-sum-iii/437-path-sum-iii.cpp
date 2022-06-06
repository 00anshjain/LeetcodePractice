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
    int ans = 0;
    void pathsum(TreeNode* root, int target, vector<long long> arr)
    {
        if(!root)
            return;
        int k = root->val;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            arr[i] += (long long)k;
            if(arr[i] == (long long)target)
                ans++;
        }
        arr.push_back(k);
        if(k == target)
            ans++;
        pathsum(root->left, target, arr);
        pathsum(root->right, target, arr);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        vector<long long> arr;
        pathsum(root, targetSum, arr);
        return ans;
    }
};