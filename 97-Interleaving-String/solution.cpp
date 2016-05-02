class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(),
            len2 = s2.length();
        if (len1 + len2 != s3.length())
            return false;
        vector<vector<bool>> visit(len1 + 1, vector<bool>(len2 + 1, false));
        stack<pair<int, int>> stk;
        visit[0][0] = true;
        stk.push(make_pair(0, 0));
        while (!stk.empty() && !visit[len1][len2]) {
            int l1 = stk.top().first,
                l2 = stk.top().second;
            stk.pop();
            if (s1[l1] == s3[l1 + l2] && !visit[l1 + 1][l2]) {
                visit[l1 + 1][l2] = true;
                stk.push(make_pair(l1 + 1, l2));
            }
            if (s2[l2] == s3[l1 + l2] && !visit[l1][l2 + 1]) {
                visit[l1][l2 + 1] = true;
                stk.push(make_pair(l1, l2 + 1));
            }
        }
        return visit[len1][len2];
    }
};