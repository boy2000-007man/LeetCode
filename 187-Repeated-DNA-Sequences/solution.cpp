class Solution {
    int tran(char c) {
        switch (c) {
            case 'A':return 0;
            case 'C':return 1;
            case 'G':return 2;
            case 'T':return 3;
            default:return -1;
        }
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<int, int> um;
        for (int i = 0, idx = 0; s[i]; i++, idx <<= 2) {
            idx |= tran(s[i]);
            if (9 <= i && um[idx & 0xfffff]++ == 1)
                result.push_back(s.substr(i - 9, 10));
        }
        return result;
    }
};