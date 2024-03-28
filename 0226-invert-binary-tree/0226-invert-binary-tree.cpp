class Solution {
public:
    // void fun(TreeNode* root) {
    //     if(root == NULL) {
    //         return;
    //     }
    //     TreeNode* swap = root->left;
    //     root->left = root->right;
    //     root->right = swap;
    //     fun(root->left);
    //     fun(root->right);
    // }

    TreeNode* invertTree(TreeNode* root) {
        // if(root == NULL) {
        //     return NULL;
        // }
        // fun(root);
        // return root;
         if(root == NULL)
        {
            return root;
        }
        queue<TreeNode *> q;
       q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            TreeNode * temp = q.front();
            q.pop();
            TreeNode* swa = temp->right;
            temp->right  = temp->left;
            temp->left = swa;
             if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
        return root;
    }
};
