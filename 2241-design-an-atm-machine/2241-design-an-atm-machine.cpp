class ATM {
public:
    vector<vector<long long>> vec;
    ATM() {
        vec.push_back({20,0});
        vec.push_back({50,0});
        vec.push_back({100,0});vec.push_back({200,0});vec.push_back({500,0});
    }
    
    void deposit(vector<int> b) {
        for(int i=0;i<b.size();i++){
            vec[i][1]+=b[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);
        bool isvalid=1;
        int idx=4;
        while(idx>=0&&amount){
        
            
            int val=amount/vec[idx][0];
            // cout<<val<<","<<amount<<","<<vec[idx][0]<<","<<vec[idx][1]<<"  ";
            
            
            
            if(vec[idx][1]==0||val==0){
                val=0;
            }else if(val<=vec[idx][1]){
                
                amount-=val*vec[idx][0];
                vec[idx][1]-=val;
            }else {
                amount-=vec[idx][1]*vec[idx][0];
                val=vec[idx][1];
                vec[idx][1]=0;
                
            }
                
            if(vec[idx][0]==20){
                ans[0]+=val;
            }else if(vec[idx][0]==50) ans[1]+=val;
            else if(vec[idx][0]==100)ans[2]+=val;
            else if(vec[idx][0]==200) ans[3]+=val;
            else ans[4]+=val;
            idx--;
        }
        // cout<<endl;
        if(amount>0){
            for(int i=0;i<5;i++){
                vec[i][1]+=ans[i];
            }
            return {-1};
        }
        return ans;
        
        
        
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */