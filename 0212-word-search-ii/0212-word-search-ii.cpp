class Solution
{
public:
    struct Node
    {
        Node *links[26];
        bool flag = false;
        bool containsKey(char key)
        {
            return links[key - 'a'];
        }
        bool hasEnd()
        {
            return flag;
        }
        Node *getNode(char key)
        {
            return links[key - 'a'];
        }
        void put(char key)
        {
            links[key - 'a'] = new Node();
        }
        void setEnd()
        {
            flag = true;
        }
        void removeEnd()
        {
            flag = false;
        }
    };

    Node *root = new Node();

    void insert(string word)
    {
        Node *p = root;

        for (char &key : word)
        {
            if (!p->containsKey(key))
            {
                p->put(key);
            }
            p = p->getNode(key);
        }
        p->setEnd();
    }

    vector<vector<int>> visited;
    vector<string> ans;

    void s(vector<vector<char>> &board, string &word, int i, int j, Node *p)
    {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] == 1 || (!p->containsKey(board[i][j]))) return;

        word += board[i][j];
        p = p->getNode(board[i][j]);

        if (p->hasEnd())
        {
            p->removeEnd();
            ans.push_back(word);
        }

        visited[i][j] = 1; 
        s(board, word, i, j + 1, p); s(board, word, i, j - 1, p); s(board, word, i - 1, j, p);  s(board, word, i + 1, j, p); 
        visited[i][j] = 0;

        word.pop_back();
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        visited = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        for (auto &ss : words) insert(ss); 
        Node *p = root;
        string word; 
        for (int i = 0; i < board.size(); i++) for (int j = 0; j < board[0].size(); j++) s(board, word, i, j, p); 
        return ans;
    }
};