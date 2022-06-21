class Solution {
public:
    void findAllComb(unordered_set<int> &vec,int a,int b,int c){
        if(a){
            vec.insert(a*100+b*10+c);
             vec.insert(a*100+c*10+b);
        }
        if(b){
             vec.insert(b*100+a*10+c);
            vec.insert(b*100+c*10+a);
        }
        if(c){
            vec.insert(c*100+a*10+b);
            vec.insert(c*100+b*10+a);
        }
    }
    vector<int> findEvenNumbers(vector<int>& d) {
        unordered_set<int> vec;
        vector<int>ans;
        for(int i=0;i<d.size();i++){
            for(int j=i+1;j<d.size();j++){
                for(int k=j+1;k<d.size();k++){
                    findAllComb(vec,d[i],d[j],d[k]);
                }
            }
        }
        for(auto i:vec){
            if(i%2==0)
            ans.push_back(i);
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};