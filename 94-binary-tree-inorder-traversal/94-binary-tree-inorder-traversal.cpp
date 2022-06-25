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
    void helper(TreeNode* root,TreeNode* ptr){
        while(root->right){
            root=root->right;
        }
        root->right=ptr;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        while(root){
            TreeNode* ptr=root;
            TreeNode* k=root->left;
            if(root->left){
                root=root->left;
                ptr->left=NULL;
                helper(root,ptr);
                root=k;
            }else{
                vec.push_back(root->val);
                root=root->right;
            }
        }
        return vec;
    }
};