class Solution {
public:
    pair<int, bool> maxDepthAndBalanced(TreeNode* root) {
        if (root == NULL)
            return make_pair(0, true);

        auto left = maxDepthAndBalanced(root->left);
        auto right = maxDepthAndBalanced(root->right);

        int depth = max(left.first, right.first) + 1;
        bool balanced = left.second && right.second && abs(left.first - right.first) <= 1;

        return make_pair(depth, balanced);
    }

    bool isBalanced(TreeNode* root) {
        return maxDepthAndBalanced(root).second;
    }
};
