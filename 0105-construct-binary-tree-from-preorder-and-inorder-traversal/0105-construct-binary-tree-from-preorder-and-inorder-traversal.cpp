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
    TreeNode* build(vector<int>&preorder,int psrt,int pend,vector<int>&inorder,int insrt,int inend,
                   map<int,int>&m)
    {
        if(psrt>pend || insrt>inend)
            return NULL;
        TreeNode *node=new TreeNode(preorder[psrt]);
        int index=m[node->val];
        int left=index-insrt;
        
        node->left=build(preorder,psrt+1,psrt+left,inorder,insrt,index-1,m);
        node->right=build(preorder,psrt+left+1,pend,inorder,index+1,inend,m);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        TreeNode *root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
    
    
};