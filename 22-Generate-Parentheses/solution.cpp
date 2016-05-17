class Solution {
    void search(vector<string> &result, string &s, int n1, int n2, int l) {
        if (!n1 && !n2)
            result.push_back(s);
        else {
            if (n1) {
                s[l] = '(';
                search(result, s, n1 - 1, n2, l + 1);
            }
            if (n1 < n2) {
                s[l] = ')';
                search(result, s, n1, n2 - 1, l + 1);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s(n << 1, ' ');
        search(result, s, n, n, 0);
        return result;
    }
};