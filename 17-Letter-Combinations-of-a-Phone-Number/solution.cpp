class Solution {
    string tran(char c) {
        switch (c) {
            case '2':return "abc";
            case '3':return "def";
            case '4':return "ghi";
            case '5':return "jkl";
            case '6':return "mno";
            case '7':return "pqrs";
            case '8':return "tuv";
            case '9':return "wxyz";
            default:return "";
        }
    }
    void search(vector<string> &result, string &digits, string &comb, int l) {
        if (digits[l])
            for (char c: tran(digits[l])) {
                comb[l] = c;
                search(result, digits, comb, l + 1);
            }
        else if (l)
            result.push_back(comb);
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string comb(digits.length(), ' ');
        search(result, digits, comb, 0);
        return result;
    }
};