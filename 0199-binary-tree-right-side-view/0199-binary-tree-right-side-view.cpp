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
    void find(vector<int>&ans,TreeNode *root,int level)
    {
        if(root==NULL)
            return;
        if(level==ans.size())
            ans.push_back(root->val);
        find(ans,root->right,level+1);
        find(ans,root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        find(ans,root,0);
        return ans;
    }
};