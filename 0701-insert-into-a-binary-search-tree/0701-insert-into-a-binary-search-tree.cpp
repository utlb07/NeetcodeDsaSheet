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
    TreeNode* fun(TreeNode* root, int data)
    {
        if(root==NULL)
        {
            root=new TreeNode(data);
            return root;
        }
        if(root->val>data)
        {
            root->left=fun(root->left,data);
        }
        else
        {
            root->right=fun(root->right,data);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return fun(root,val);
    }
};