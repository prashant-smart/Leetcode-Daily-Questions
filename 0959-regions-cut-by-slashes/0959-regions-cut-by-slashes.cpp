class Solution {
public:
   int cnt, n;
   vector<int> f;
   int regionsBySlashes(vector<string>& grid) {
        n = grid.size()+1;
        cnt = 1;
        for (int i = 0; i < n*n*4 ; ++i)
            f.push_back(i);
       for (int i = 1; i <n; ++i) {
           //  cout<<g(0,i)<<" "<<g(0,i-1)<<endl;
           // cout<<g(n-1,i)<<" "<<g(n-1,i-1)<<endl;
           // cout<<g(i,0)<<" "<<g(i-1,0)<<endl;
           // cout<<g(i,n-1)<<" "<<g(i-1,n-1)<<endl;
              unite(g(0,i),g(0,i-1));
              unite(g(n-1,i),g(n-1,i-1));
              unite(g(i,0),g(i-1,0));
              unite(g(i,n-1),g(i-1,n-1));
       }
       
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < n-1; ++j) {
                if (grid[i][j] == '/') {
                    // cout<<i<<"-"<<j<<endl;
                    int isvalid=unite(g(i , j+1), g(i +1, j));
                    if(isvalid) cnt++;
                }
                 if (grid[i][j] == '\\') {
                    int isvalid=unite(g(i , j), g(i +1, j+1));
                    if(isvalid) cnt++;
                }
            }
        }
        return cnt;
    }

    int find(int x) {
        if (x != f[x]) {
            f[x] = find(f[x]);
        }
        return f[x];
    }
    bool unite(int x, int y) {
        // cout<<x<<" "<<y<<endl;
        x = find(x); y = find(y);
        if (x != y) {
            f[x] = y;
            return 0;
        }
        return 1;
    }
    int g(int i, int j) {
        return (i * n + j);
    }
};