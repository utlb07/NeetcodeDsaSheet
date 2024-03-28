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
    int id;
    TreeNode* buildtree(vector<int>& preorder, vector<int>& inorder,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[id]);
        id++;
        int ind;
        for(int i=start;i<end;i++)
        {
            if(inorder[i]==root->val)
            {
                ind=i;
                break;
            }
        }
        root->left=buildtree(preorder,inorder,start,ind-1);
        root->right=buildtree(preorder,inorder,ind+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildtree(preorder,inorder,0,inorder.size()-1);
        //return ans;
    }
};