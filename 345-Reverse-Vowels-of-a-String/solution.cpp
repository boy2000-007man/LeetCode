class Solution {
public:
    string reverseVowels(string s) {
        bitset<256> vowel;
        vowel['a'] = vowel['i'] = vowel['u'] = vowel['e'] = vowel['o'] = 1;
        for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
            while (l < r && !vowel[tolower(s[l])])
                l++;
            while (l < r && !vowel[tolower(s[r])])
                r--;
            if (l < r)
                swap(s[l], s[r]);
        }
        return s;
    }
};