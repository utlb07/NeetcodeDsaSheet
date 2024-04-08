class Solution {
    int out = INT_MAX;
    TreeNode* pre;
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return out;
    }
    void inorder(TreeNode* node){
        if(!node)
            return;

        inorder(node->left);
        
        if(pre)
            out = min(out,abs(node->val - pre->val));
        
        pre = node;
        inorder(node->right);
    }
};