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
    TreeNode* junctionNode;
    vector<bool> findJnode(TreeNode* root, int startValue, int destValue){
        if(!root) return {0,0,0};
        
        bool first=0,sec=0;
        if(root->val==startValue) first=1;
        else if(root->val==destValue) sec=1;
        
        auto leftP=findJnode(root->left,startValue,destValue);
        auto rightP=findJnode(root->right,startValue,destValue);
        
        if(leftP[2]||rightP[2]) return {0,0,1};
        
        bool finalFirst=leftP[0]|rightP[0]|first;
        bool finalSecond=leftP[1]|rightP[1]|sec;
        
        if(finalFirst&&finalSecond){
            
            junctionNode=root;
            return {1,1,1};
        }
        
        return {finalFirst,finalSecond,0};
        
    }
    
    bool findPath(TreeNode* root, int val,string &s){
        if(!root) return 0;
        if(root->val==val) return 1;
        
        
        bool left=findPath(root->left,val,s);
        bool right=findPath(root->right,val,s);
        
        if(left){
            s.push_back('L');
            return 1;
        }
        if(right){
            s.push_back('R');
            return 1;
        }
        return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        findJnode(root,startValue,destValue);
        
        string s1,s2;
        
        findPath(junctionNode,startValue,s1);
        findPath(junctionNode,destValue,s2);
        
        string ans;
        for(auto i:s1) ans.push_back('U');
        reverse(begin(s2),end(s2));
        
        return ans+s2;
    }
};