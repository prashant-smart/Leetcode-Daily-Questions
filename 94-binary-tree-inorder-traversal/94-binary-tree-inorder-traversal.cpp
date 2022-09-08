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
    vector<int> morisTraversal(TreeNode* root) {
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int>ans;
        while(1){
            if(root){
                st.push(root);
                root=root->left;
            }else{
                if(st.size()==0) return ans;
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int>ans;
        while(1){
            if(root){
                ans.push_back(root->val);
                st.push(root);
                root=root->left;
            }else{
                if(st.size()==0) return ans;
                root=st.top();
                st.pop();
                
                root=root->right;
            }
        }
        return ans;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* temp;
        vector<int>ans;
        while(1){
            if(root){
                st.push(root);
                root=root->left;
            }else{
                if(st.size()==0) return ans;
                temp=st.top()->right;
                if(!temp){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(st.size()&&temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }else root=temp;
            }
        }
        return ans;
    }
};