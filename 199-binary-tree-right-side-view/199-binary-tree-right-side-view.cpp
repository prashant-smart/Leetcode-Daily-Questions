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
   
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        if(!root) return vec;
        queue<TreeNode*> q;
        vec.push_back(root->val);
        q.push(root);
        while(q.size()){
            TreeNode* temp;
            queue<TreeNode*> c;
            while(q.size()){
                TreeNode* ptr=q.front();
                q.pop();
                if(ptr->left){ c.push(ptr->left);temp=ptr->left;}
                if(ptr->right){ c.push(ptr->right);temp=ptr->right;}
            }
            vec.push_back(temp->val);
            q=c;
        }
        vec.pop_back();
        return vec;
        
    }

};