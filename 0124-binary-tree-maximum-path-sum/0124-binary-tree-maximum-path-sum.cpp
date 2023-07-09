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
    int find(TreeNode *root,int &sum)
    {
        int l=0,r=0;
        if(root==NULL)
            return 0;
        l=max(0,find(root->left,sum));// max-> For ignoring negative values.
        r=max(0,find(root->right,sum));// max-> For ignoring negative values.
        sum=max(sum,l+r+root->val);
        
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        find(root,sum);
        return sum;
    }
};