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
    
    void inorder(TreeNode *ptr,int &ans,int &prev)
    {
        if(ptr->left!=NULL)
            inorder(ptr->left,ans,prev);
        
        ans=min(ans,abs(ptr->val-prev));
        prev=ptr->val;
        
        if(ptr->right!=NULL)
            inorder(ptr->right,ans,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        
        TreeNode *ptr=root;
        int ans=INT_MAX,prev=INT_MAX;
        inorder(ptr,ans,prev);
        return ans;     
    }
};