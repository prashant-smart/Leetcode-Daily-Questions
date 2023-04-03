class Solution {
public:
    
    int memo[500+1][500+1];
    int solve(string word1, string word2, int i,int j){
        if(i==0)
            return j;
        if(j==0)
            return i;
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(word1[i-1]==word2[j-1])
            return memo[i][j]=solve(word1,word2,i-1,j-1);
        
        return memo[i][j]=min(solve(word1,word2,i-1,j)+1,min(
                    solve(word1,word2,i,j-1)+1,
                    solve(word1,word2,i-1,j-1)+1));
        
    }
    
    int minDistance(string word1, string word2) {
        memset(memo,-1,sizeof(memo));
        return solve(word1,word2,word1.length(),word2.length());
    }
    //  int minDistance(string word1, string word2) {
    //     int m = word1.size(), n = word2.size();
    //     vector<int> pre(n + 1, 0), cur(n + 1, 0);
    //     for (int j = 1; j <= n; j++) {
    //         pre[j] = j;
    //     }
    //     for (int i = 1; i <= m; i++) {
    //         cur[0] = i;
    //         for (int j = 1; j <= n; j++) {
    //             if (word1[i - 1] == word2[j - 1]) {
    //                 cur[j] = pre[j - 1];
    //             } else {
    //                 cur[j] = min(pre[j - 1], min(cur[j - 1], pre[j])) + 1;
    //             }
    //         }
    //         fill(pre.begin(), pre.end(), 0);
    //         swap(pre, cur);
    //     }
    //     return pre[n];
    // }
};