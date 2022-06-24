class Solution {
public:
    bool isPossible(vector<int>& target) {
        unsigned long long int sum=0;
        priority_queue<int> que;
        
        for(auto i:target){
            sum+=i;
            if(i!=1)
                que.push(i);
        }
        
        while(que.size()){
            unsigned long long int leftSum=sum-que.top();
            // cout<<leftSum<<","<<sum<<" ";
            if(leftSum>=que.top()||leftSum==0) return 0;
            
            
            if(leftSum==1||(que.top()-1)%leftSum==0){
                sum-=(que.top()-1);
                que.pop();
            }else{
                sum-=que.top();
                unsigned long long int val=que.top()%leftSum;
                sum+=val;
                cout<<val<<endl;
                que.pop();
                que.push(val);
                
            }
            
        }
        return 1;
    }
};