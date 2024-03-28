class Solution {
public:
    void fun(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        TreeNode* swap = root->left;
        root->left = root->right;
        root->right = swap;
        fun(root->left);
        fun(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        fun(root);
        return root;
    }
};
