class Solution {
public:
   
    string orderlyQueue(string s, int k) {
          if(k == 1)
        {
            int n = s.size();
            string doubleStr = s+s;
            string result = s;
            for(int i=1; i<n; i++)
            {
                string str = doubleStr.substr(i, n);
                if(str < result)
                {
                    result = str;
                }
            }
            
            return result;
        }
        
        sort(s.begin(), s.end());
        return s;
        
    }
};