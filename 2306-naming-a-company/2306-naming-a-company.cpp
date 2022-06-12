class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
    long long res = 0;
    unordered_set<string> s(begin(ideas), end(ideas));
    int cnt[128][128] = {};
    for (auto i = 0; i < ideas.size(); ++i) {
        char first = ideas[i][0];
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            ideas[i][0] = ch;
            cnt[ch][first] += s.count(ideas[i]) == 0;
        }
    }
    for (auto a = 'a'; a <= 'z'; ++a)
        for (auto b = 'a'; b <= 'z'; ++b)
            res += cnt[a][b] * cnt[b][a];
    return res;
}
};