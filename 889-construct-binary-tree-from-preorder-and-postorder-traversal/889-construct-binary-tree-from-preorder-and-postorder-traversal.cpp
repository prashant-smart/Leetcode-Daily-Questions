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
    unordered_map<int,int> um;
    int idx = 0;

    TreeNode * dfs(vector<int>& preorder, int s, int e, vector<int>& postorder){
        if(s > e)
            return NULL;
        if(s == e)
            return new TreeNode(preorder[idx++]);

        int pos = um[preorder[idx+1]];

        TreeNode * root = new TreeNode(preorder[idx++]);
        root->left      = dfs(preorder, s, pos, postorder);
        root->right     = dfs(preorder, pos+1, e-1, postorder);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        int pos = postorder.size();
        for(int i = 0; i<pos; i++)
            um[postorder[i]] = i;

        return dfs(preorder, 0, pos-1, postorder);
    }
};