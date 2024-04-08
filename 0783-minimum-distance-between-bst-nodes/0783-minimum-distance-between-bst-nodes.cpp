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
    int out = INT_MAX;
    TreeNode* pre;
      void inorder(TreeNode* node){
        if(!node)
            return;

        inorder(node->left);
        
        if(pre)
            out = min(out,abs(node->val - pre->val));
        
        pre = node;
        inorder(node->right);
    }
    int minDiffInBST(TreeNode* root) {
          inorder(root);
        return out;
    }
};