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
    void solve(TreeNode* root,unordered_map<int,int>&umap){
        if(!root) return ;
        umap[root->val]++;
        solve(root->left,umap);
        solve(root->right,umap);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> umap;
        solve(root,umap);
        
        for(auto i:umap){
            if(k-i.first==i.first){
                if(i.second>1) return 1;
            }else if(umap.count(k-i.first)){
                return 1;
            }
        }
        return 0;
    }
};