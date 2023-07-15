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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>nodes;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto prev=q.front();
            q.pop();
            TreeNode *node=prev.first;
            int x=prev.second.first,y=prev.second.second;
            nodes[x][y].insert(node->val);
            
            if(node->left)
                q.push({node->left,{x-1,y+1}});
            if(node->right)
                q.push({node->right,{x+1,y+1}});
        }
        
        vector<vector<int>>ans;
        for(auto x:nodes)
        {
            vector<int>col;
            for(auto y:x.second)
            {
                col.insert(col.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};