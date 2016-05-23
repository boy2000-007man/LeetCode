class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0,
            pre = 0;
        for (char c: s)
            if (c != ' ')
                len++;
            else if (len) {
                pre = len;
                len = 0;
            }
        return len ? len : pre;
    }
};