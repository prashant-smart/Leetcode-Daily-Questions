class Solution {
public:
    unordered_map<string,int> umap;
    void helper(vector<vector<char>>& board,int i,int j,unordered_set<string>&ans,string& temp){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]=='*'){
            return ;
        }
        
        
        char curr=board[i][j];
        temp.push_back(curr);
  
        if(!umap.count(temp)){  temp.pop_back(); return ;}
        // cout<<temp<<" "<<i<<" "<<j<<" "<<umap[temp]<<endl; 
        if( umap[temp]) ans.insert(temp);
        
        board[i][j]='*';
        
        helper(board,i+1,j,ans,temp);
        helper(board,i-1,j,ans,temp);
        helper(board,i,j+1,ans,temp);
        helper(board,i,j-1,ans,temp);
        
        board[i][j]=curr;
        temp.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(auto &it:words){
            string temp;
            for(int i=0;i<it.length();i++){
                temp.push_back(it[i]);
                if(i==it.length()-1||umap[temp]==1){
                    umap[temp]=1;
                }else umap[temp]=0;
            }
        }
        
        unordered_set<string> ans;
        string s;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                helper(board, i, j,ans,s);
            }
        }
        vector<string> a;
        for(auto &i:ans){
            a.push_back(i);
        }
        return a;
    }
};


