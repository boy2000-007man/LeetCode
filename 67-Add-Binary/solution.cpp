class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        for (int l = a.length() - 1, r = b.length() - 1, o = 0; 0 <= l || 0 <= r || o; o >>= 1) {
            if (0 <= l)
                o += a[l--] - '0';
            if (0 <= r)
                o += b[r--] - '0';
            result += o & 1 ? '1' : '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};