class Solution {
public:
    long long MOD = 1000000007;
    int numWays(vector<string>& words, string target) 
    {
        int m = words.size(), n = words[0].size();
        vector<vector<int>>freq(n, vector<int>(26, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char ch = words[i][j];
                freq[j][ch - 'a']++; //freq of 'ch' in jth col
            }
        }
        //===================================================================================================
         //TOP DOWN => 
        //  1)[colIdx = j], we expected results for [colIdx = j + 1]
        //  2)[targetIdx = k], we expected results for [targetIdx = k + 1]
        //BOTTOM UP => 
        //  1) We calculate [col = j + 1] results first
        //     Then use them in [colIdx = j] :)
        //  2) We calculate [targetIdx = k + 1] results first
        //     Then use them in [targetIdx = k] :)
        
        int targetSize = target.size();
        vector<vector<int>>dp(n + 1, vector<int>(targetSize + 1, 0));
        for (int colIdx = n; colIdx >= 0; colIdx--)
        {
            for (int targetIdx = targetSize; targetIdx >= 0; targetIdx--)
            {
                //SAME BASE CONDITIONS AS IN TOP DOWN
                if (targetIdx == targetSize) { dp[colIdx][targetIdx] = 1; continue; }
                if (colIdx == n) { dp[colIdx][targetIdx] = 0; continue; }
                
                char targetCh = target[targetIdx];
                int notPickWays = dp[colIdx + 1][targetIdx];
                //===================================================================
                int pickWays = 0;
                if (freq[colIdx][targetCh - 'a'] != 0)
                {
                    int currWays = freq[colIdx][targetCh - 'a'];
                    int nextWays = dp[colIdx + 1][targetIdx + 1];
                    pickWays = (currWays * (long long)nextWays) % MOD;
                }
                //====================================================================
                dp[colIdx][targetIdx] = ((pickWays + (long long)notPickWays) % MOD);
            }
        }
        return dp[0][0];
    }
};