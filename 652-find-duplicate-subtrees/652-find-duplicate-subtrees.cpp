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
    string getDup(TreeNode* root, unordered_map<string, vector<TreeNode*>> &mp)
    {
        if(root == NULL)
            return "";
        string s = "(";
        s += getDup(root->left, mp);
        s += to_string(root->val);
        s += getDup(root->right, mp);
        s += ")";
        mp[s].push_back(root);
        return s;
}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> mp;
        getDup(root, mp);
        vector<TreeNode*> res;
        for(auto itr : mp)
        {
            if(itr.second.size() > 1)
                res.push_back((itr.second)[0]);
        }
        return res;
    }
};