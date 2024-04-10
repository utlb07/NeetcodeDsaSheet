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
    string fun(TreeNode* root,unordered_map<string,int>&mp,vector<TreeNode*>&vt)
    {
        if(root==NULL)
        {
            return "";
        }
        string str=to_string(root->val)+","+fun(root->left,mp,vt)+","+fun(root->right,mp,vt);
        mp[str]++;
        if(mp[str]==2)
        {
            vt.push_back(root);
        }
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        vector<TreeNode*>vt;
        fun(root,mp,vt);
        return vt;
    }
};