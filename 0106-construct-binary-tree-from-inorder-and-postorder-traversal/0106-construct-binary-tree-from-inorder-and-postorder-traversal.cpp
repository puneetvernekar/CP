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
    map<int,int>m;
    TreeNode *construct(vector<int>&postorder,int psrt,int pend,vector<int>&inorder,int isrt,int iend)
    {
        if(pend<psrt || isrt>iend)
            return NULL;
        TreeNode *node=new TreeNode(postorder[pend]);
        int index=m[node->val];
        int left=index-isrt;
        
        node->left=construct(postorder,psrt,psrt+left-1,inorder,isrt,index-1);
        node->right=construct(postorder,psrt+left,pend-1,inorder,index+1,iend);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        TreeNode *root=construct(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
        
        return root;
    }
};