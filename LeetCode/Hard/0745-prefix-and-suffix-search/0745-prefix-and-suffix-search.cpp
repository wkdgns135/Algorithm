class WordFilter {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int index = -1;
    };
    
    TrieNode* root;
    
public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            string word = words[i] + "{";  // '{'는 알파벳보다 큰 값 (구분자 역할)
            int len = word.size();
            
            for (int j = 0; j < len; j++) {
                TrieNode* node = root;
                // 모든 가능한 접두사와 접미사의 조합을 Trie에 삽입
                for (int k = j; k < 2 * len - 1; k++) {
                    char c = word[k % len]; 
                    if (!node->children.count(c)) {
                        node->children[c] = new TrieNode();
                    }
                    node = node->children[c];
                    node->index = i; // 가장 마지막에 나온 단어의 인덱스를 저장
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string query = suff + "{" + pref;
        TrieNode* node = root;
        
        for (char c : query) {
            if (!node->children.count(c)) return -1;
            node = node->children[c];
        }
        return node->index;
    }
};
