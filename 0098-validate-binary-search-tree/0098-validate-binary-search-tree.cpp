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
    // void help(TreeNode *root, bool &flag)
    // {
    //     if(root==NULL || flag==false || (root->left==NULL && root->right==NULL))
    //         return;
    //     if(root->left==NULL && root->right!=NULL)
    //     {    
    //         if(root->right->val>root->val)
    //             return;
    //         else
    //             flag=false;
    //     }
    //     else if(root->left!=NULL && root->right==NULL)
    //     {    
    //         if(root->left->val<root->val)
    //             return;
    //         else
    //             flag=false;
    //     }
    //     else if(root->val>root->left->val && root->val<root->right->val)
    //     {
    //         help(root->left,flag);
    //         help(root->right,flag);
    //     }
    //     else
    //         flag=false;
    // }
    bool find(TreeNode *root,long long minl,long long maxr)
    {
        if(root==NULL)
            return true;
        if(root->val>minl && root->val<maxr)
            return find(root->left,minl,root->val) && find(root->right,root->val,maxr);
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return true;
        return find(root,LONG_MIN,LONG_MAX);
    }
};