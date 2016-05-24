class LRUCache{
    struct Int {
        int val;
        Int(int value = -1) : val(value) {
        }
    };
    list<int> lst;
    unordered_map<int, pair<Int, list<int>::iterator>> um;
    int limit;
public:
    LRUCache(int capacity) : limit(capacity) {
    }
    
    int get(int key) {
        auto &p = um[key];
        if (p.first.val != -1) {
            lst.push_front(key);
            lst.erase(p.second);
            p.second = lst.begin();
        }
        return p.first.val;
    }
    
    void set(int key, int value) {
        auto &p = um[key];
        lst.push_front(key);
        if (p.first.val != -1)
            lst.erase(p.second);
        else if (limit < lst.size()) {
            um[lst.back()].first.val = -1;
            lst.pop_back();
        }
        p.first.val = value;
        p.second = lst.begin();
    }
};