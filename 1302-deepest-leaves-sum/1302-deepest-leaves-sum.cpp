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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int s=0;
        while(!q.empty())
        {
            s=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                s+=cur->val;
                if(cur->left!=NULL)
                q.push(cur->left);
                if(cur->right!=NULL)
                q.push(cur->right);
            }
        }
        return s;
    }
};