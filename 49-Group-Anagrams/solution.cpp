class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (auto &s: strs) {
            string t(s);
            sort(t.begin(), t.end());
            um[t].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &p: um) {
            result.push_back(p.second);
            sort(result.back().begin(), result.back().end());
        }
        return result;
    }
};