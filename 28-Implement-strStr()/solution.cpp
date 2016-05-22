class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.length(),
            nlen = needle.length();
        vector<int> equal(nlen <= hlen ? nlen : 0, 1),
                    offset(equal);
        for (int i = 1; i < equal.size(); i++) {
            equal[i] = offset[i] = equal[i - 1];
            while (equal[i] <= i && needle[i - equal[i]] != needle[i])
                equal[i] += offset[i - equal[i]];
            while (offset[i] <= i && needle[i - offset[i]] == needle[i])
                offset[i] += offset[i - offset[i]];
        }
        for (int i = 0, j = 0; i - j <= hlen - nlen; )
            if (!needle[j])
                return i - j;
            else if (haystack[i] == needle[j])
                i++, j++;
            else if ((j -= offset[j]) < 0)
                i++, j = 0;
        return -1;
    }
};