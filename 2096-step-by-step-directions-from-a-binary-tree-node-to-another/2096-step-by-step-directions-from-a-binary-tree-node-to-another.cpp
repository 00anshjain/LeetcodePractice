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
    TreeNode* getLCA(TreeNode* root, int s, int d)
    {
        if(!root)
            return NULL;
        if(root->val == s || root->val == d)
            return root;
        TreeNode* l = getLCA(root->left, s, d);
        TreeNode* r = getLCA(root->right, s, d);
        if(l != NULL && r != NULL)
            return root;
        if(l)
            return l;
        return r;
    }
    bool getNode(TreeNode* root, int d, string& path)
    {
        if(!root)
            return false;
        if(root->val == d)
            return true;
        path += 'L';
        if(getNode(root->left, d, path))
            return true;
        path.pop_back();
        // if(s1[0] != 'N')
        //     return s1 + 'L';
        path += 'R';
        if(getNode(root->right, d, path))
            return true;
        path.pop_back();
        return false;
        // return "N";
    }
    // string getNode2(TreeNode* root, int d)
    // {
    //     if(!root)
    //         return "N";
    //     if(root->val == d)
    //         return "";
    //     string s1 = getNode2(root->left, d);
    //     if(s1 != "N")
    //         return s1 + 'U';
    //     string s2 = getNode2(root->right, d);
    //     if(s2 != "N")
    //         return s2 + 'U';
    //     return "N";
    // }
    
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode* head = getLCA(root, s, d);
        // cout<<head->val<<endl;
        string s1, s2;
        getNode(head, d, s1);
        // reverse(s1.begin(), s1.end());
        getNode(head, s, s2);
        for(auto &c : s2)
            c = 'U';
        return s2 + s1;
    }
};