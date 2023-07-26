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
    int help(TreeNode *root)
    {
        int height=0;
        while(root)
        {
            height++;
            root=root->left;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lhgt=help(root);
        int rhgt=help(root->right);
        if(lhgt==rhgt)
            return 2^lhgt-1;
        return 1+countNodes(root->left)+countNodes(root->right);
        // cout<<lhgt<<" "<<rhgt<<endl;
        // int ans=2^lhgt+2^rhgt-1;
        // return ans;
    }
};