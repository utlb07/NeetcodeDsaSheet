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
    typedef unsigned long long ll;
   
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        ll ans=0;
        q.push({root,0});
        while(!q.empty())
        {
            ll n=q.size();
            ll left=q.front().second;
            ll right=q.back().second;
            ans=max(ans,right-left+1);
            
            while(n--)
            {
            TreeNode* curr=q.front().first;
            ll id=q.front().second;
            q.pop();
                
                if(curr->left!=NULL)
                {
                    q.push({curr->left,2*id+1});
                }
                if(curr->right!=NULL)
                {
                    q.push({curr->right,2*id+2});
                }
            }
                
            
        }
        return ans;
        
    }
};