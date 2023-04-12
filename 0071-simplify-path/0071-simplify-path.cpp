class Solution {
public:
    string simplifyPath(string path) {
        string newPath="";
        for(int i=0;i<path.length();i++){
            
            if(path[i]=='/'){
                while(i<path.length()&&path[i]=='/'){
                    i++;
                }
                newPath+="/";
                if(i<path.length())
                    newPath.push_back(path[i]);
            }else{
               newPath.push_back(path[i]);
            }

        }
        path=newPath;
        string ans="";
        // cout<<path<<" ";
        int i=0;
        while(i<path.length()){
            if(path[i]=='/'){
                ans+="/";
                i++;
            }else{
                string direc;
                while(i<path.length()&&path[i]!='/'){
                    direc.push_back(path[i]);
                    i++;
                }
                if(direc==".."){
                    if(ans.length()>1){
                        ans.pop_back();
                        while(ans.back()!='/')
                            ans.pop_back();
                    }
                    i++;
                   
                }else if(direc=="."){
                    i++;
                }
                else if(direc=="..."){
                    ans+="...";
                }else{
                    ans+=direc;
                }
            }
            
        }
        if(ans!="/"&&ans.back()=='/')
            ans.pop_back();
        return ans;
    }
};