class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        
        vector<int> freq(26, -1);
        
        // freq[i] = -1 - indicates that the char is not visited
        // freq[i] = -2 - indicates that the char is visited twice
        // freq[i] = [0..n-1] - indicates that the char is visited once with index as its value
        
        for(int i=0; i<n; i++)
        {
            int val = s[i]-'a';
            
            if(freq[val] == -1)
                freq[val] = i;
            else if(freq[val] >= 0)
                freq[val] = -2;
        }
        
        
        int min_idx = INT_MAX;
        
        for(int i=0; i<26; i++)
        {
            if(freq[i] >= 0 && freq[i] < min_idx)
            {
                min_idx = freq[i];
            }
        }
        
        if(min_idx == INT_MAX)
            return -1;
        return min_idx;
    }
};