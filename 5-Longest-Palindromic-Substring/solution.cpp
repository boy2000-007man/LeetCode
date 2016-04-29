class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> occur(256, 0);
        int odd_count = 0;
        for (char c: s)
            if (++occur[c] & 1)
                odd_count++;
            else
                odd_count--;
        int slen = s.length(),
            len = slen - max(0, odd_count - 1);
        for (int i = len; i < slen; i++)
            if (--occur[s[i]] & 1)
                odd_count++;
            else
                odd_count--;
        for ( ; len; len--) {
            vector<int> occur_cpy(occur);
            int odd_count_cpy = odd_count;
            for (int i = 0; i <= slen - len; i++) {
                if (odd_count < 2 && !((len ^ odd_count) & 1)) {
                    bool palindromic = true;
                    for (int j = 0; j < len - j - 1 && palindromic; j++)
                        if (s[i + j] != s[i + len - j - 1])
                            palindromic = false;
                    if (palindromic)
                        return s.substr(i, len);
                }
                if (--occur[s[i]] & 1)
                    odd_count++;
                else
                    odd_count--;
                if (++occur[s[i + len]] & 1)
                    odd_count++;
                else
                    odd_count--;
            }
            occur.swap(occur_cpy);
            odd_count = odd_count_cpy;
            if (--occur[s[len - 1]] & 1)
                odd_count++;
            else
                odd_count--;
        }
        return "";
    }
};