class Solution {
public:
    
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;   
        set<pair<int,int>> incPairs,descPairs;
        int prev=0;
        int last=0;
        vector<int> incVal(ratings.size(),1);
        vector<int> desVal=incVal;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]<=ratings[i-1]){
                if(prev!=last)
                    incPairs.insert({prev,last});
                prev=i;
            }
            last=i;
        }
        if(last!=prev){
            incPairs.insert({prev,last});
        }
        last=prev=ratings.size()-1;
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]<=ratings[i+1]){
                if(prev!=last)
                    descPairs.insert({prev,last});
                last=i;
            }
            prev=i;
        }
        
        if(last!=prev){
            descPairs.insert({prev,last});
        }
        
        for(auto pr:incPairs){
            int mark=1;
            for(int i=pr.first;i<=pr.second;i++){
                incVal[i]=mark++;
            }
        }
        for(auto pr:descPairs){
            int mark=1;
            for(int i=pr.second;i>=pr.first;i--){
                desVal[i]=mark++;
            }
        }
        // for(auto i:desVal) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:incVal) cout<<i<<" ";
        // cout<<endl;
        int ans=0;
        for(int i=0;i<ratings.size();i++){
            if(i==0){
                if(ratings[i]>ratings[i+1]){
                    ans+=max(desVal[i],incVal[i]);
                }else{
                    if(desVal[i]!=INT_MAX){
                        ans+=desVal[i];
                    }else if(incVal[i]!=INT_MAX){
                        ans+=incVal[i];
                    }else ans++;
                }
            }else if(i==ratings.size()-1){
                if(ratings[i]>ratings[i-1])
                    ans+=max(desVal[i],incVal[i]);
                else{
                    if(desVal[i]!=INT_MAX){
                        ans+=desVal[i];
                    }else if(incVal[i]!=INT_MAX){
                        ans+=incVal[i];
                    }else ans++;
                }
            }else{
                if(ratings[i]>ratings[i-1]||ratings[i]>ratings[i+1]){
                    ans+=max(desVal[i],incVal[i]);
                }else{
                    if(desVal[i]!=INT_MAX){
                        ans+=desVal[i];
                    }else if(incVal[i]!=INT_MAX){
                        ans+=incVal[i];
                    }else ans++;
                }
            }
        }
        return ans;
    }
};