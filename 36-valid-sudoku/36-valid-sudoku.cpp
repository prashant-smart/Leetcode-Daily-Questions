class Solution {
public:
    int direction[9][2]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> st;
        for(int i=0;i<board.size();i+=3){
            for(int j=0;j<board[0].size();j+=3){
                for(auto dic:direction){
                    if(st.count(board[i+dic[0]][j+dic[1]])){
                        return 0;
                    }
                    if(board[i+dic[0]][j+dic[1]]!='.'){
                        st.insert(board[i+dic[0]][j+dic[1]]);
                    }
                }
                st.clear();
            }
        }
        unordered_set<char> st1;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(st.count(board[i][j])){
                        return 0;
                   }
                if(board[i][j]!='.'){
                    st.insert(board[i][j]);
                }
                
                if(st1.count(board[j][i])){
                        return 0;
                   }
                if(board[j][i]!='.'){
                    st1.insert(board[j][i]);
                }
            }
            st.clear(),st1.clear();
        }
        return 1;
    }
};