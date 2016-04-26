class Solution {
public:
    string countAndSay(int n) {
        string result("1");
        stringstream ss;
        for (int i = 1; i < n; i++) {
            ss.str("");
            int count = 1;
            for (int j = 0; result[j]; j++)
                if (result[j] == result[j + 1])
                    count++;
                else {
                    ss << count << result[j];
                    count = 1;
                }
            result = ss.str();
        }
        return result;
    }
};