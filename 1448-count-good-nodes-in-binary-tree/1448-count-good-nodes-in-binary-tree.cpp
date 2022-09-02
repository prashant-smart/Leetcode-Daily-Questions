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
    int helper(TreeNode* root,int val){
        if(!root) return 0;
        int ans=0;
        if(root->val>=val) ans++;
      
        return ans+helper(root->left,max(val,root->val))+helper(root->right,max(val,root->val));
        
    }
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};