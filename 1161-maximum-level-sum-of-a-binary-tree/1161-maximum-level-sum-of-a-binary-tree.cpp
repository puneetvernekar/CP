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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *>q;
        int ans,level=0,maxi=INT_MIN;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size(),sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode *cur=q.front();
                sum+=cur->val;
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            level++;
            if(sum>maxi)
            {    
                maxi=sum;
                ans=level;
            }
        }
        return ans;
    }
};