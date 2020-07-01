

class Solution {
private:
    struct Node {
        vector<Node*> ch;
        bool is_word;

        Node() : ch(26, nullptr), is_word(false) {};
    };
    
    Node* root = nullptr;
    vector<string> ans;
    
    void addWord(string& s) {
        Node* curr = root;
        for (int i = 0; i < s.size(); ++i) {
            if (curr->ch[s[i]-'a'] == nullptr) curr->ch[s[i]-'a'] = new Node;
            
            if (i == s.size() - 1) curr->ch[s[i]-'a']->is_word = true;
            
            curr = curr->ch[s[i]-'a'];
        }
    }
    
    void createTrie(vector<string> &words) {
        root = new Node;
        for (auto &e: words) addWord(e);
    }
    
    void checkAddWordHelper(vector<vector<char>> &board, int i, int j, string &s,
                            vector<vector<int>> &checked, Node* curr) {      
        if (curr->ch[board[i][j] - 'a'] == nullptr) return;
        
        curr = curr->ch[board[i][j] - 'a'];
        s += board[i][j];
        checked[i][j] = 1;
        
        if (i-1 >=0 && checked[i-1][j] == 0) checkAddWordHelper(board, i-1, j, s, checked, curr);
        if (i+1 < board.size() && checked[i+1][j] == 0) checkAddWordHelper(board, i+1, j, s, checked, curr);
        if (j-1 >=0 && checked[i][j-1] == 0) checkAddWordHelper(board, i, j-1, s, checked, curr);
        if (j+1 < board[0].size() && checked[i][j+1] == 0) checkAddWordHelper(board, i, j+1, s, checked, curr);
        
        if (curr->is_word == true) {
            ans.push_back(s);
            curr->is_word = false;
        }
        
        s.pop_back();
        checked[i][j] = 0;
    };
    
    void checkAddWord(vector<vector<char>> &board, int i, int j) {
        string s;
        vector<vector<int>> checked( board.size(), vector<int>(board[0].size(), 0));
        checkAddWordHelper(board, i, j, s, checked, root);
    }
    
    void findWords(vector<vector<char>> &board) {
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                checkAddWord(board, i, j);
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        createTrie(words);
        findWords(board);
        
        return ans;
    }
};
