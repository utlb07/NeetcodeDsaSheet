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
    void fun(TreeNode* root,bool &ans,int &s,int tar)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            if(root->left==NULL&&root->right==NULL)
            {
                s+=root->val;
                if(s==tar)
                {
                    ans=true;
                    return;
                }
                s-=root->val;
                return;
            }
        }
         s+=root->val;
    fun(root->left,ans,s,tar);
    fun(root->right,ans,s,tar);
    s-=root->val;
    }

    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=false;
        int s=0;
        fun(root,ans,s,targetSum);
        return ans;
    }
};