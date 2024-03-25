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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
            int x=q.size();
            vector<int>a;
            for(int i=0;i<x;i++)
            {
                TreeNode* it=q.front();
                q.pop();
                a.push_back(it->val);
                if(it->left!=NULL)
                {
                    q.push(it->left);
                }
                if(it->right!=NULL)
                {
                    q.push(it->right);
                }
                
            }
            ans.push_back(a);
        }
        return ans;
    }
};