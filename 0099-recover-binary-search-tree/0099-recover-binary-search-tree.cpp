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
    void help(TreeNode *root,TreeNode *&prev,TreeNode *&n1,TreeNode *&n2)
    {
        if(root==NULL)
            return;
        help(root->left,prev,n1,n2);
        
        if(prev->val>root->val)
        {
            if(n1==NULL)
                {n1=prev;
                n2=root;}
            else
                n2=root;
        }

        prev=root;
        help(root->right,prev,n1,n2);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *n1=NULL,*n2=NULL;
        TreeNode *prev=new TreeNode(INT_MIN);
        help(root,prev,n1,n2);
        swap(n1->val,n2->val);
    }
};