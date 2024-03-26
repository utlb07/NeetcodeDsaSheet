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
    vector<int> rightSideView(TreeNode* root) {
          vector<int>a;
        if(root==NULL)
        {
           return a;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int x=q.size();
            for(int i=0;i<x;i++)
            {
                auto it=q.front();
                q.pop();
                if(i==x-1)
                {
                    a.push_back(it->val);
                }
                if(it->left!=NULL)
                {
                    q.push(it->left);
                }
                if(it->right!=NULL)
                {
                    q.push(it->right);
                }
            }
            
        }
        return a;
    }
};