class Solution {

    
public:
    string reverseWords(string s) {
        
        int n = s.length();
		
		//create one temp string and str string 
        string temp;
        string str = "";
        
        for(int i=0; i<n; i++){
		// if we get space between words then if condition will be applied
            if(s[i] == ' '){
			
				// reverse the word 
                reverse(str.begin(), str.end());
				
				// concatenating reverse word present in str string with temp string
                temp = temp + str + " ";
                str = "";
            }else{
				// extracting the word letter by letter until we get space(' ')
                str += s[i];
            }  
        }
		// reversing the last word as we don't have space at last of the string so we need to reverse the last word also
        reverse(str.begin(), str.end());
        temp = temp + str;
        
        return temp;
    }
};