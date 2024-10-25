
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // Map of child nodes
    bool isEndOfWord; // Flag to check if the node represents the end of a word

    TrieNode() : isEndOfWord(false) {} // Constructor to initialize isEndOfWord to false
};

class Trie {
private:
    TrieNode* root; // Root of the trie

public:
    /** Initialize the trie. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root; // Start from the root
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                // If the character does not exist, create a new TrieNode
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch]; // Move to the child node
        }
        node->isEndOfWord = true; // Mark the end of the word
    }
    
    /** Returns true if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root; // Start from the root
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false; // Character not found, return false
            }
            node = node->children[ch]; // Move to the child node
        }
        return node->isEndOfWord; // Return true if we reached the end of a word
    }
    
    /** Returns true if there is a previously inserted word that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root; // Start from the root
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false; // Character not found, return false
            }
            node = node->children[ch]; // Move to the child node
        }
        return true; // If we successfully traversed the prefix, return true
    }
};