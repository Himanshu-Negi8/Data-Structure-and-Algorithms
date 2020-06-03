class TrieNode {
    public:
        bool isEnd = false;
        TrieNode *children[26];
        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = NULL;

            isEnd = false;
        }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for (char cur : word) {
            int index = cur - 97;
            if (node->children[index] == NULL) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       TrieNode * node = root;
       for (char cur : word) {
            int index = cur - 97;
            if (node->children[index] != NULL) {
                node = node->children[index];
                continue;
            }
            return 0;
       }
        if (node->isEnd == true) {
            return 1;
        }
        return 0;       
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * node = root;
        for (char cur : prefix) {
            int index = cur - 97;
            if (node->children[index] != NULL) {
                node = node->children[index];
                continue;
            }
            return 0;
       }
        return 1;       
    }
};
