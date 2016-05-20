class Solution {
    void search(vector<string> &result, vector<vector<bool>> &link, vector<int> &route, const string &s, int loc) {
        route.push_back(0);
        for (int i = loc + 1; s[i]; i++)
            if (link[loc][i])
                search(result, link, route, s, route.back() = i);
        route.pop_back();
        if (link[loc].back()) {
            result.push_back(s);
            for (int i = 0; i < route.size(); i++)
                result.back().insert(i + route[i], " ");
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
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
        vector<string> result;
        vector<int> route;
        if (visit.back())
            search(result, link, route, s, 0);
        return result;
    }
};