class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> vec;
        for(int i=0;i<mat[0].size();i++){
            int a=0;
            int b=i;
            while(a<mat.size()&&b<mat[0].size()){
                vec.push_back(mat[a++][b++]);
            }
            sort(begin(vec),end(vec));
            reverse(begin(vec),end(vec));
            a=0;
            b=i;
            
            while(a<mat.size()&&b<mat[0].size()&&vec.size()){
                mat[a++][b++]=vec.back();
                vec.pop_back();
            }
        }
        for(int i=0;i<mat.size();i++){
            int a=i;
            int b=0;
            while(a<mat.size()&&b<mat[0].size()){
                vec.push_back(mat[a++][b++]);
            }
            sort(begin(vec),end(vec));
            reverse(begin(vec),end(vec));
            a=i;
            b=0;
            
            while(a<mat.size()&&b<mat[0].size()&&vec.size()){
                mat[a++][b++]=vec.back();
                vec.pop_back();
            }
        }
        return mat;
    }
};