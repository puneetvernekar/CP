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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(root->val==key)
            return help(root);
        TreeNode *node=root;
        while(node)
        {
            if(node->val>key)
            {
                if(node->left!=NULL && node->left->val==key)
                {
                    node->left=help(node->left);
                    break;
                }
                else
                    node=node->left;   
            }
            else
            {
                if(node->right!=NULL && node->right->val==key)
                {
                    node->right=help(node->right);
                    break;
                }
                else
                    node=node->right;
            }
        }
        return root;
    }
    
    TreeNode* help(TreeNode *node)
    {
        if(node->left==NULL)
            return node->right;
        if(node->right==NULL)
            return node->left;
        
        TreeNode *rightHead=node->right;
        TreeNode *LeftrightChild=node->left;
        
        while(LeftrightChild->right)
            LeftrightChild=LeftrightChild->right;
        
        LeftrightChild->right=rightHead;
        return node->left;
        
    }
};