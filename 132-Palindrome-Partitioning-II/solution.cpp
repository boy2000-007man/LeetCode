class Solution {
    int search(string &s, vector<int> &count, int len) {
        if (count[len] != INT_MAX)
            return count[len];
        int size = len + 1 >> 1;
        int equal[size] = {1},
            offset[size] = {1};
        for (int i = 1; i < size; i++) {
            for (equal[i] = equal[i - 1]; 0 <= i - equal[i] && s[len - 1 - i] != s[len - 1 - (i - equal[i])]; equal[i] += offset[i - equal[i]]);
            for (offset[i] = equal[i - 1]; 0 <= i - offset[i] && s[len - 1 - i] == s[len - 1 - (i - offset[i])]; offset[i] += offset[i - offset[i]]);
        }
        for (int i = 0, j = 0; i < len && count[len]; )
            if (s[i] == s[len - 1 - j])
                if (len - 1 - j <= i + 2) {
                    count[len] = min(count[len], search(s, count, i - j) + 1);
                    if ((j -= equal[j]) < 0)
                        i++, j = 0;
                } else
                    i++, j++;
            else if ((j -= offset[j]) < 0)
                i++, j = 0;
        return count[len];
    }
public:
    int minCut(string s) {
        vector<int> count(s.length() + 1, INT_MAX);
        count[0] = -1;
        return search(s, count, s.length());
    }
};