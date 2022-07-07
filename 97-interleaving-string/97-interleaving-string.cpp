class Solution {
public:
   unordered_map<string,bool> mem;
    bool check(string s1,string s2,string s3,int len1,int len2,int len3,int p1,int p2)
    {
        if(p1+p2==len3)
            return true;
        
        string key = to_string(p1)+" "+to_string(p2);
        if(mem.count(key))
            return mem[key];
        
        if(p1==len1)
            return mem[key] = s2[p2]==s3[p1+p2]? check(s1,s2,s3,len1,len2,len3,p1,p2+1):false;
        if(p2==len2)
            return mem[key] = s1[p1]==s3[p1+p2]? check(s1,s2,s3,len1,len2,len3,p1+1,p2):false;
        
        bool one = false,two = false;
        if(s1[p1]==s3[p1+p2])
            one = check(s1,s2,s3,len1,len2,len3,p1+1,p2);
        if(s2[p2]==s3[p1+p2])
            two = check(s1,s2,s3,len1,len2,len3,p1,p2+1);
        
        return mem[key] = one || two;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;
        return check(s1,s2,s3,s1.length(),s2.length(),s3.length(),0,0);
    }
};