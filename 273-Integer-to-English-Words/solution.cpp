class Solution {
    string i2s(int i) {
        static vector<string> word1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"},
                              word2 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"},
                              word3 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string s;
        if (i / 100 % 10)
            s += word1[i / 100 % 10] + " Hundred";
        if (1 < i / 10 % 10) {
            if (!s.empty())
                s += " ";
            s += word2[i / 10 % 10];
            if (i % 10)
                s += " " + word1[i % 10];
        } else if (i / 10 % 10) {
            if (!s.empty())
                s += " ";
            s += word3[i % 10];
        } else if (i % 10) {
            if (!s.empty())
                s += " ";
            s += word1[i % 10];
        }
        return s;
    }
public:
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        vector<int> divisor = {1000000000, 1000000, 1000, 1};
        vector<string> postfix = {" Billion", " Million", " Thousand", ""},
                       part;
        for (int i = 0; i < 4; i++) {
            part.push_back(i2s(num / divisor[i]));
            if (!part.back().empty())
                part.back() += postfix[i];
        }
        string result;
        for (auto &p: part) {
            if (!result.empty() && !p.empty())
                result += " ";
            result += p;
        }
        return result;
    }
};