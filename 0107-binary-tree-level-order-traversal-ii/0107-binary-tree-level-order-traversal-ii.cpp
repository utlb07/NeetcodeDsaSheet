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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        int cnt=0;
        while(!q.empty())
        {
            int x=q.size();
            vector<int>a;
            for(int i=0;i<x;i++)
            {
                TreeNode* it=q.front();
                q.pop();
                cnt++;
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
            // if(cnt%2!=0)
            // {
            //     reverse(a.begin(),a.end());
            // }
            ans.push_back(a);
        }
        reverse(ans.begin(),ans.end());
        return ans;   
    }
};