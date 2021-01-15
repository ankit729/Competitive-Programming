// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd=false;
        for(int i=0;i<26;++i)
            children[i]=NULL;
    }
};
class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr=root;
        for(auto& ch:word){
            int index=ch-'a';
            if(!curr->children[index])
                curr->children[index]=new TrieNode();
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr=root;
        for(auto& ch:word){
            int index=ch-'a';
            if(!curr->children[index])
                return false;
            curr=curr->children[index];
        }
        return curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(auto& ch:prefix){
            int index=ch-'a';
            if(!curr->children[index])
                return false;
            curr=curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
