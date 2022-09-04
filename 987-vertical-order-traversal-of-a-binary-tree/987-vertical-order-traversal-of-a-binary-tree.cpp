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
    map< pair<int,int>,vector<int>>umap;
    void solve(TreeNode* root,int idx,int h){
        if(!root) return;
        umap[{idx,h}].push_back(root->val);
        solve(root->left,idx-1,h+1);
        solve(root->right,idx+1,h+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>vec;
        solve(root,0,0);
        map<int,vector<int>> U;
        for(auto iter:umap){
            sort(iter.second.begin(),iter.second.end());
             pair<int, int> k=iter.first;
            for(auto i:iter.second){
                U[k.first].push_back(i);
            }
            cout<<k.first<<" ";
        }
        for(auto iter:U){
            vec.push_back(iter.second);
        }
        return vec;
    }
};