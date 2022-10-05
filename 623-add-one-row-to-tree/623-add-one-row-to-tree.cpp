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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode *new_node = new TreeNode(val);
            new_node->left=root;
            return new_node;
        }
        queue<TreeNode *>q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            count++;
            for(int i=0;i<size;i++)
            {
                TreeNode *store=q.front();
                q.pop();
                if(count==depth-1)
                {
                        TreeNode *new_node=new TreeNode(val);
                        TreeNode *store_left=store->left;
                        store->left=new_node;
                        new_node->left=store_left;
                        TreeNode *new_nodee=new TreeNode(val);
                        TreeNode *store_right=store->right;
                        store->right=new_nodee;
                        new_nodee->right=store_right;
                }
                if(store->left!=NULL)
                {
                    q.push(store->left);
                }
                if(store->right!=NULL)
                {
                    q.push(store->right);
                }
            }
        }
        return root;
    }
};