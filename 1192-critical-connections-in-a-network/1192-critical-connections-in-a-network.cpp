class Solution {
public:
     vector<vector<int>> ans;
    
    void eval_node_value(int parent,int curr_ver,unordered_map<int,vector<int>>& adjLis,unordered_map<int,int>& node_val,int &count){
        
        node_val[curr_ver]=++count;
        int val=node_val[curr_ver];
        for(auto ngh:adjLis[curr_ver]){
            if(parent==ngh) continue;
            if(!node_val.count(ngh)){
                eval_node_value(curr_ver,ngh,adjLis,node_val,count);
            }
            node_val[curr_ver]=min(node_val[curr_ver],node_val[ngh]);
            
            if(val<node_val[ngh]){
                ans.push_back({curr_ver,ngh});
            }
        }
        
    }
    // void fillAns(unordered_map<int,vector<int>>& adjLis,unordered_map<int,int>& node_val){
    //     set<vector<int>> st;
    //     for(auto node:adjLis){
    //         for(auto ngh:adjLis[node.first]){
    //             if(node_val[node.first]<node_val[ngh]){
    //                 vector<int> temp={node.first,ngh};
    //                 sort(begin(temp),end(temp));
    //                 st.insert(temp);
    //             }
    //         }
    //     }
    //     for(auto elm:st){
    //         ans.push_back(elm);
    //     }
    // }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> adjLis;
        unordered_map<int,int> node_val;
        for(auto elm: connections){
            adjLis[elm[0]].push_back(elm[1]);
            adjLis[elm[1]].push_back(elm[0]);
        }
        int count=0;
        eval_node_value(-1,0,adjLis,node_val,count);
        // fillAns(adjLis,node_val);
        return ans;
        
    }
};