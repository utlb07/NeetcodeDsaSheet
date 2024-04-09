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
  void fun(vector<vector<int>>& paths, vector<int>& path, TreeNode* node,
             int sum) 
  {
        if (node == NULL) {
            return;
        }
        path.push_back(node->val);
        if (!(node->left) && !(node->right) && sum == node->val)
            paths.push_back(path);
        fun(paths, path, node->left, sum - node->val);
        fun(paths, path, node->right, sum - node->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        fun(paths, path,root, targetSum);
        return paths;
    }
};