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
    void change(vector<int>&vec,int i,int j){
        if(i>=j) return;
        int val=vec[j];
        // cout<<val<<" "
        for(int k=j;k>=i+1;k--){
            vec[k]=vec[k-1];
        }
        vec[i]=val;
    }
    void helper(vector<int>&vec,int i,int j){
        if(i>=j) return ;
        int mid=i+(j-i)/2;
        helper(vec,i,mid-1);
        helper(vec,mid+1,j);
        change(vec,i,mid);
        return ;
        
    }
    TreeNode* build(TreeNode* root,int val){
        if(root==NULL)
            root=new TreeNode(val);
        else if(val<=root->val)
            root->left=build(root->left,val);
        else if(val>root->val)
            root->right=build(root->right,val);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root=NULL;
        for(int i=0;i<preorder.size();i++){
            root=build(root,preorder[i]);
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        helper(nums,0,nums.size()-1);
        // for(auto iter:nums)cout<<iter<<" ";
        return bstFromPreorder(nums);
        
    }
};