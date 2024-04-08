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
    TreeNode* bst(vector<int>& nums,int i,int j)
    {
        if(i>j)
        {
            return NULL;
        }
        int mid=i+(j-i)/2;
        TreeNode* temp=new TreeNode(nums[mid]);
        temp->left=bst(nums,i,mid-1);
        temp->right=bst(nums,mid+1,j);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        return bst(nums,0,j);
    }
};