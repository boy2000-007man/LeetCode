class Solution {
public:
    string fractionToDecimal(long long int numerator, long long int denominator) {
        stringstream ss;
        if (numerator && ((numerator ^ denominator) >> 63 & 1))
            ss << '-';
        ss << (numerator = abs(numerator)) / (denominator = abs(denominator));
        if (numerator %= denominator) {
            ss << '.';
            string decimal;
            unordered_map<long long int, bool> um;
            while ((numerator %= denominator) && !um[numerator]++)
                decimal += static_cast<char>('0' + (numerator *= 10) / denominator);
            if (!numerator)
                ss << decimal;
            else {
                int len = decimal.length() - 1;
                for (auto i = numerator; ((i *= 10) %= denominator) != numerator; len--);
                ss << decimal.substr(0, len) << '(' << decimal.substr(len) << ')';
            }
        }
        return ss.str();
    }
};