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
      unordered_map<int,int> umap;
    TreeNode* makeTree(vector<int>& preorder, vector<int>& postorder,int &i,int posStart,int posEnd){
        if(posEnd<posStart){
            return NULL;
        }
        TreeNode* head=new TreeNode(preorder[i++]);
        head->left=makeTree(preorder,postorder,i,posStart,umap[head->val]-1);
        head->right=makeTree(preorder,postorder,i,umap[head->val]+1,posEnd);
        return head;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++) umap[inorder[i]]=i;
        int i=0;
        return makeTree(preorder,inorder,i,0,inorder.size()-1);
    }
    
};