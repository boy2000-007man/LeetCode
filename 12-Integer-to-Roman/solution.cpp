class Solution {
    void search(string &str, string s, int &num, int n) {
        for ( ; n <= num; num -= n)
            str += s;
    }
public:
    string intToRoman(int num) {
        static vector<pair<string, int>> cost = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
            {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4},
            {"I", 1}};
        string result;
        for (auto &p: cost)
            search(result, p.first, num, p.second);
        return result;
    }
};