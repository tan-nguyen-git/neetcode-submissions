class PrefixTree {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord = false;
    };

    TrieNode* root = nullptr;

public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char ch : word) {

            // If this character doesn't exist,
            // create a new TrieNode
            if (!curr->children.contains(ch)) {
                curr->children[ch] = new TrieNode();
            }

            // Move down the trie
            curr = curr->children[ch];
        }

        // We finished the entire word
        curr->isEndOfWord = true;
    }
    bool search(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if(!curr->children.contains(ch))
            {
                return false;
            }
            curr= curr->children[ch];
        }


        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if(!curr->children.contains(ch))
            {
                return false;
            }
            curr= curr->children[ch];
        }
        return true;
    }
};
    
  

