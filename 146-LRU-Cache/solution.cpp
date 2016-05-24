class LRUCache{
    list<pair<int, int>> lst;
    unordered_map<int, pair<bool, list<pair<int, int>>::iterator>> um;
    int limit;
public:
    LRUCache(int capacity) : limit(capacity) {
    }
    
    int get(int key) {
        auto &p = um[key];
        if (!p.first)
            return -1;
        else {
            lst.push_front(*p.second);
            lst.erase(p.second);
            return (p.second = lst.begin())->second;
        }
    }
    
    void set(int key, int value) {
        if (get(key) != -1)
            lst.front().second = value;
        else {
            lst.push_front({key, value});
            um[key] = {true, lst.begin()};
            if (limit < lst.size()) {
                um[lst.back().first].first = false;
                lst.pop_back();
            }
        }
    }
};