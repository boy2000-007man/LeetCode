class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> code(1, 0);
        vector<bool> visit(1 << n, false);
        visit[0] = true;
        while (code.size() < visit.size())
            for (int i = 0; i < n; i++)
                if (!visit[code.back() ^ 1 << i]) {
                    code.push_back(code.back() ^ 1 << i);
                    visit[code.back()] = true;
                    break;
                }
        return code;
    }
};