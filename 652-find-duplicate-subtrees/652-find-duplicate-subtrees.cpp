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
    string getDup(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &res)
    {
        if(root == NULL)
            return "";
        string s = "(";
        s += getDup(root->left, mp, res);
        s += to_string(root->val);
        s += getDup(root->right, mp, res);
        s += ")";
        mp[s]++;
        if(mp[s] == 2)
            res.push_back(root);
        return s;
}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> res;
        getDup(root, mp, res);
        // for(auto itr : mp)
        // {
        //     if(itr.second.size() > 1)
        //         res.push_back((itr.second)[0]);
        // }
        return res;
    }
};