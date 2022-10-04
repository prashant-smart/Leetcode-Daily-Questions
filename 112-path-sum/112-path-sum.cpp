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
    bool solve(TreeNode* root, int &ts,int sum){
        if(!root) return 0;
        if(!root->left&&!root->right) return sum+root->val==ts;
        return solve(root->left,ts,sum+root->val)||solve(root->right,ts,sum+root->val);
        
    }
    bool hasPathSum(TreeNode* root, int ts) {
        if(!root) return 0;
        return solve(root,ts,0);
    }
};