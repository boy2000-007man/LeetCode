class Solution {
    static bool cmp(const string &s1, const string &s2) {
        return s2.length() < s1.length();
    }
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        vector<int> length(words.size()),
                    feature(words.size(), 0);
        for (int i = 0; i < words.size(); i++)
            for (int &j = length[i] = 0; words[i][j]; j++)
                feature[i] |= 1 << words[i][j] - 'a';
        int product = 0;
        for (int i = 0; i < words.size() && product < pow(length[i], 2); i++)
            for (int j = i + 1, p; j < words.size() && product < (p = length[i] * length[j]); j++)
                if (!(feature[i] & feature[j]))
                    product = p;
        return product;
    }
};