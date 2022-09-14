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
    int ans=0;
    
    
    void dfs(TreeNode* root,unordered_map<int,int> &umap){
        if(!root) return;
        if(!root->left&&!root->right){
            umap[root->val]++;
            int check=0;
            for(auto i:umap){
                if(i.second%2!=0) check++;
            }
            if(check<2) ans++;
            umap[root->val]--;
            return ;
        }
        
        umap[root->val]++;
        dfs(root->left,umap);
        dfs(root->right,umap);
        umap[root->val]--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> umap;
        dfs(root,umap);
        return ans;
    }
};