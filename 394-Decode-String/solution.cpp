class Solution {
public:
    string decodeString(string s) {
        stack<string> encoded_string;
        encoded_string.push("");
        stack<int> k;
        bool num = false;
        for (auto c: s)
            if ('0' <= c && c <= '9')
                if (num) {
                    k.top() *= 10;
                    k.top() += c - '0';
                } else {
                    num = true;
                    k.push(c - '0');
                }
            else if (c == '[') {
                num = false;
                encoded_string.push("");
            } else if (c == ']') {
                string t = encoded_string.top();
                encoded_string.pop();
                while (k.top()--)
                    encoded_string.top() += t;
                k.pop();
            } else
                encoded_string.top() += c;
        return encoded_string.top();
    }
};