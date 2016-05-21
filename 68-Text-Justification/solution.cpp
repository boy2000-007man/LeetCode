class Solution {
    int calc(int n, int k) {
        return k ? (n + k - 1) / k : n;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int start = 0;
        for (int i = 0, slen = 0, wlen; i < words.size(); i++)
            if (maxWidth < (slen += (wlen = words[i].length())) + (i - start)) {
                result.push_back("");
                for (int tot = maxWidth - (slen - wlen), num; start < i; tot -= num)
                    result.back() += words[start++] + string(num = calc(tot, i - 1 - start), ' ');
                slen = wlen;
            }
        if (start < words.size()) {
            for (result.push_back(""); start < words.size(); start++)
                result.back() += words[start] + ' ';
            result.back().resize(maxWidth, ' ');
        }
        return result;
    }
};