class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int slen = s.length();
        vector<vector<bool>> link(slen, vector<bool>(slen + 1, false));
        for (auto &word: wordDict)
            for (int i = 0, wlen = word.length(); (i = s.find(word, i)) != string::npos; i++)
                link[i][i + wlen] = true;
        vector<bool> visit(slen + 1, false);
        visit[0] = true;
        for (int i = 0; i < link.size() && !visit.back(); i++)
            if (visit[i])
                for (int j = i + 1; j < link[i].size(); j++)
                    if (link[i][j])
                        visit[j] = true;
        return visit.back();
    }
};