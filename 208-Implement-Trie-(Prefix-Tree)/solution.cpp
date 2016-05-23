class TrieNode {
public:
    bool end;
    TrieNode *next[26];
    // Initialize your data structure here.
    TrieNode() : end(false) {
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (char c: word) {
            if (!p->next[c - 'a'])
                p->next[c - 'a'] = new TrieNode();
            p = p->next[c - 'a'];
        }
        p->end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (char c: word)
            if (!(p = p->next[c - 'a']))
                return false;
        return p->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char c: prefix)
            if (!(p = p->next[c - 'a']))
                return false;
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");