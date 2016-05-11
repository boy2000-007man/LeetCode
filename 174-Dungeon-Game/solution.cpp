class Solution {
    pair<int, int> calc(pair<int, int> p, int tp) {
        if (0 <= p.second + tp)
            return make_pair(p.first, p.second + tp);
        else
            return make_pair(p.first + p.second + tp, 0);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<vector<pair<int, int>>>> hp;
        for (auto &v: dungeon)
            hp.push_back(vector<vector<pair<int, int>>>(v.size()));
        for (int i = 0; i < dungeon.size(); i++)
            for (int j = 0; j < dungeon[i].size(); j++)
                if (!i && !j)
                    hp[i][j].push_back(calc(make_pair(0, 0), dungeon[i][j]));
                else {
                    if (i)
                        for (auto &p: hp[i - 1][j])
                            hp[i][j].push_back(calc(p, dungeon[i][j]));
                    if (j)
                        for (auto &p: hp[i][j - 1])
                            hp[i][j].push_back(calc(p, dungeon[i][j]));
                    sort(hp[i][j].begin(), hp[i][j].end(), greater<pair<int, int>>());
                    int num = 1;
                    for (auto &p: hp[i][j])
                        if (hp[i][j][num - 1].first + hp[i][j][num - 1].second < p.first + p.second)
                            swap(p, hp[i][j][num++]);
                    hp[i][j].resize(num);
                }
        return dungeon.empty() ? 1 : 1 - hp.back().back().front().first;
    }
};