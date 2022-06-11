class Solution {
public:
     void helperForGenerateStrings(string s,unordered_set<string>& wordListSet,unordered_map<string,set<string> >& adjLis){
        string mainString=s;
        for(int pos=0;pos<mainString.size();pos++){
            char prevVal=s[pos];
            for(char c='a';c<='z';c++){
                s[pos]=c;
                if(wordListSet.count(s)&&s!=mainString){
                    adjLis[mainString].insert(s);
                }
            }
            s[pos]=prevVal;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListSet;
        wordListSet.insert(beginWord);
        
        bool isEndWordExist=0;
        
        for(auto word:wordList){
            if(word==endWord) isEndWordExist=1;
            wordListSet.insert(word);
        }
        
        if(!isEndWordExist){
            return {};
        }
        
        unordered_map<string,set<string> > adjLis;
        for(auto iter:wordListSet){
            string str=iter;
            helperForGenerateStrings(str,wordListSet,adjLis);
        }
        
        
        int lengthOfSequence=1;
        queue<vector<string>> validPathQueue;
        validPathQueue.push({beginWord});
        
        unordered_set<string> visitedWord;
        
        bool isBreak=0;
        
        while(validPathQueue.size()&&!isBreak){
            int size=validPathQueue.size();
            while(size--){
                vector<string> currVec=validPathQueue.front();
                string currWord=currVec.back();
                if(currWord==endWord){
                    isBreak=1;
                    break;
                };
                
                validPathQueue.pop();
                visitedWord.insert(currWord);
                
                for(auto ngh:adjLis[currWord]){
                    
                    if(!visitedWord.count(ngh)){
                        // cout<<ngh<<"->"<<lengthOfSequence<<endl;
                        vector<string> temp=currVec;
                        temp.push_back(ngh);
                        validPathQueue.push(temp);
                    }
                }
                
            }
            lengthOfSequence++;
        }
        
        vector<vector<string>> ans;
        // cout<<<<" ";
        while(validPathQueue.size()){
            auto vec=validPathQueue.front();
            validPathQueue.pop();
            // cout<<vec.back()<<" ";
            if(vec.back()==endWord&&vec.size()==lengthOfSequence-1){
                ans.push_back(vec);
            }
        }
        return ans;
    }
};