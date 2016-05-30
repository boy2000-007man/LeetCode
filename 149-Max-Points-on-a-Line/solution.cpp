/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
bool operator<(const Point &p1, const Point &p2) {
    return make_pair(p1.x, p1.y) < make_pair(p2.x, p2.y);
}
bool operator==(const Point &p1, const Point &p2) {
    return make_pair(p1.x, p1.y) == make_pair(p2.x, p2.y);
}
class Solution {
    string k(Point &p1, Point &p2) {
        stringstream ss;
        long long int x = p1.x,
                      y = p1.y;
        x -= p2.x, y -= p2.y;
        if (!x)
            ss << "0,1";
        else if (!y)
            ss << "1,0";
        else {
            if ((x ^ y) >> 63 & 1)
                ss << "-";
            x = abs(x), y = abs(y);
            auto d = x;
            for (auto t = y; t %= d; swap(d, t));
            ss << x / d << "," << y / d;
        }
        return ss.str();
    }
public:
    int maxPoints(vector<Point>& points) {
        sort(begin(points), end(points));
        vector<pair<int, Point>> vec;
        for (auto &p: points)
            if (!vec.empty() && vec.back().second == p)
                vec.back().first++;
            else
                vec.push_back({1, p});
        int result = 0;
        for (auto &s: vec) {
            result = max(result, s.first);
            unordered_map<string, int> um;
            for (auto &e: vec)
                if (&s != &e)
                    um[k(s.second, e.second)] += e.first;
            for (auto &p: um)
                result = max(result, s.first + p.second);
        }
        return result;
    }
};