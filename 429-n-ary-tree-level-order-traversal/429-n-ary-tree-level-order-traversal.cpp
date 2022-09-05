/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*> que;
        vector<vector<int>> ans;
        que.push(root);
        ans.push_back({root->val});
        
        while(que.size()){
            int size=que.size();
                            vector<int> temp;

            while(size--){
                Node* curr=que.front();
                que.pop();
                for(auto ngh:curr->children){
                    que.push(ngh);
                    temp.push_back(ngh->val);
                }
                
            }
            if(temp.size())
                    ans.push_back(temp);
        }
        return ans;
    }
};