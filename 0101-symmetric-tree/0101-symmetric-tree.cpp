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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return find(root->left,root->right);
    }
    bool find(TreeNode* left,TreeNode *right)
    {
        if(left==NULL || right==NULL)
            return left==right;
        if(left->val!=right->val)
            return false;
        return find(left->left,right->right) && find(left->right,right->left);
    }
};