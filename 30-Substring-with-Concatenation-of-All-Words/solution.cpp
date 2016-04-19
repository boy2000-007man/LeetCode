class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result(0),
                    count(1, 0),
                    bitmap(256, 0),
                    bitmap_own(256, 0);
        unordered_map<string, int> s2i;
        int required = 0;
        for (string &word: words) {
            int &i = s2i[word];
            if (!i) {
                i = count.size();
                count.push_back(1);
            } else
                count[i]++;
            for (char c: word)
                if (!(bitmap[c]++))
                    required++;
        }
        int length = words[0].length(),
            total_length = words.size() * length;
        for (int i = 0; s[i]; i++) {
            if (total_length < i)
                if (bitmap_own[s[i - total_length]]-- == bitmap[s[i - total_length]])
                    required++;
            if (++bitmap_own[s[i]] == bitmap[s[i]])
                required--;
            if (!required) {
                bool sub = true;
                vector<int> count_own(count.size(), 0);
                for (int j = 0; j < words.size() && sub; j++) {
                    auto it = s2i.find(s.substr(i - total_length + 1 + j * length, length));
                    if (it == s2i.end() || count[it->second] < ++count_own[it->second])
                        sub = false;
                }
                if (sub)
                    result.push_back(i - total_length + 1);
            }
        }
        return result;
    }
};