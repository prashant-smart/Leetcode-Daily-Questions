class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        queue<pair<string,int>> que;
        for(int i=0;i<recipes.size();i++){
            que.push({recipes[i],i});
        }
        unordered_set<string> st;
        for(auto i:supplies){
            st.insert(i);
        }
        
        int n=0;
            vector<string> ans;
        while(n<=que.size()&&que.size()){
            int isvalid=1;
            pair<string,int> x=que.front();
            que.pop();
            for(auto i:ingredients[x.second]){
                if(!st.count(i)){
                    isvalid=0;
                    break;
                }
                
            }
                if(isvalid){
                    
                    st.insert(x.first);
                    ans.push_back(x.first);
                    n=0;
                }else {n++; que.push(x);}
            }
        return ans;
        }
    
    
};