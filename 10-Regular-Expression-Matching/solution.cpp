class Solution {
public:
    bool isMatch(string s, string p) {
        vector<int> sloc(1, 0);
        int ploc = 0;
        for (int slen = s.length(); !sloc.empty() && p[ploc]; ploc++) {
            vector<int> nloc;
            if (p[ploc + 1] == '*') {
                if (p[ploc] == '.')
                    for (int loc = sloc[0]; loc <= slen; loc++)
                        nloc.push_back(loc);
                else
                    for (int i = 0; i < sloc.size(); i++) {
                        nloc.push_back(sloc[i]);
                        for (int loc = sloc[i]; s[loc] == p[ploc] && (i == sloc.size() - 1 || loc + 1 < sloc[i + 1]); loc++)
                            nloc.push_back(loc + 1);
                    }
                ploc++;
            } else
                for (int loc: sloc)
                    if (s[loc] == p[ploc] || (p[ploc] == '.' && s[loc]))
                        nloc.push_back(loc + 1);
            sloc.swap(nloc);
        }
        if (!sloc.empty() && !s[sloc.back()] && !p[ploc])
            return true;
        else
            return false;
    }
};