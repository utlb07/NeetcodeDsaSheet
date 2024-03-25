class Solution {
public:
    int height(TreeNode* root, int &result) {
        if (root == NULL) {
            return 0;
        }
        int lh = height(root->left, result);
        int rh = height(root->right, result);
        result = max(result, lh + rh);
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int result = 0;
        height(root, result);
        return result;
    }
};
