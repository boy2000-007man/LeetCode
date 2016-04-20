class WordDictionary {
    struct trie_node {
        bool exist;
        int min_len,
            max_len;
        trie_node *next[26];
        trie_node() : exist(false), min_len(INT_MAX), max_len(0) {
            memset(next, 0, sizeof(next));
        }
        ~trie_node() {
            for (auto n: next)
                if (n)
                    delete n;
        }
        void add(const char *s, int length) {
            trie_node *r = this;
            for (const char *s_ = s; *s_; s_++, length--) {
                r->min_len = min(r->min_len, length);
                r->max_len = max(r->max_len, length);
                if (!r->next[*s_ - 'a'])
                    r->next[*s_ - 'a'] = new trie_node();
                r = r->next[*s_ - 'a'];
            }
            r->exist = true;
            r->min_len = 0;
        }
        bool find(const char *s, int length) {
            trie_node *r = this;
            for (const char *s_ = s; *s_; s_++, length--)
                if (length < r->min_len || r->max_len < length)
                    return false;
                else if (*s_ != '.')
                    if (r->next[*s_ - 'a'])
                        r = r->next[*s_ - 'a'];
                    else
                        return false;
                else {
                    for (char c = 'a'; c <= 'z'; c++)
                        if (r->next[c - 'a'] && r->next[c - 'a']->find(s_ + 1, length - 1))
                            return true;
                    return false;
                }
            return r->exist;
        }
    } trie_tree;
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        trie_tree.add(word.c_str(), word.length());
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie_tree.find(word.c_str(), word.length());
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");