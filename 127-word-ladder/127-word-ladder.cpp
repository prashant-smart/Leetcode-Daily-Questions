class Solution {
public:
    
    void helperForGenerateStrings(string s,unordered_set<string>& wordListSet,unordered_map<string,set<string> >& adjLis){
        string mainString=s;
        // cout<<s<<"-->";
        for(int pos=0;pos<mainString.size();pos++){
            char prevVal=s[pos];
            for(char c='a';c<='z';c++){
                s[pos]=c;
                if(wordListSet.count(s)&&s!=mainString){
                    adjLis[mainString].insert(s);
                     // cout<<s<<" ";
                }
            }
            s[pos]=prevVal;
        }
       // cout<<endl;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListSet;
        wordListSet.insert(beginWord);
        
        bool isEndWordExist=0;
        
        for(auto word:wordList){
            if(word==endWord) isEndWordExist=1;
            wordListSet.insert(word);
        }
        
        if(!isEndWordExist){
            return 0;
        }
        
        unordered_map<string,set<string> > adjLis;
        for(auto iter:wordListSet){
            string str=iter;
            // cout<<iter<<" ";
            helperForGenerateStrings(str,wordListSet,adjLis);
        }
        
        
        int lengthOfSequence=1;
        queue<string> validWordQueue;
        validWordQueue.push(beginWord);
        
        unordered_set<string> visitedWord;
        
        
        
        while(validWordQueue.size()){
            int size=validWordQueue.size();
            while(size--){
                string currWord=validWordQueue.front();
                validWordQueue.pop();
                visitedWord.insert(currWord);
                
                if(currWord==endWord) return lengthOfSequence;
                
                for(auto ngh:adjLis[currWord]){
                    if(!visitedWord.count(ngh)){
                        validWordQueue.push(ngh);
                    }
                }
                
            }
            lengthOfSequence++;
        }
        return 0;
    }
};