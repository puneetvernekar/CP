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
    int find(TreeNode* root)
    {
        int l=0,r=0;
        if(root==NULL)
            return 0;
        if(root->left)
            l=find(root->left);
        if(l==-1)
            return -1;
        if(root->right)
            r=find(root->right);
        if(r==-1)
            return -1;
        if(abs(l-r)>1)
            return -1;
        return max(l,r)+1;
        
    }
    bool isBalanced(TreeNode* root) {
        return find(root)!=-1;
    }
};