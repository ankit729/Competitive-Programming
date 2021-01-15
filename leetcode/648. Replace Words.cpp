// In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

// Return the sentence after the replacement.

 

// Example 1:

// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Example 2:

// Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// Output: "a a b c"
// Example 3:

// Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
// Output: "a a a a a a a a bbb baba a"
// Example 4:

// Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Example 5:

// Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
// Output: "it is ab that this solution is ac"
 

// Constraints:

// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 100
// dictionary[i] consists of only lower-case letters.
// 1 <= sentence.length <= 10^6
// sentence consists of only lower-case letters and spaces.
// The number of words in sentence is in the range [1, 1000]
// The length of each word in sentence is in the range [1, 1000]
// Each two consecutive words in sentence will be separated by exactly one space.
// sentence does not have leading or trailing spaces.

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
    Trie(vector<string>& words) {
        root=new TrieNode();
        for(auto& word:words)
            insert(word);
    }
    void insert(string& word) {
        TrieNode* curr=root;
        for(auto& ch:word){
            int index=ch-'a';
            if(!curr->children[index])
                curr->children[index]=new TrieNode();
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    string find(char* word) {
        TrieNode* curr=root;
        for(int i=0;word[i];++i){
            int index=word[i]-'a';
            if(!curr->children[index])
                break;
            curr=curr->children[index];
            if(curr->isEnd)
                return string(word,word+i+1);
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie trie(dictionary);
        char* word=strtok((char*)sentence.c_str()," ");
        while(word){
            ans+=trie.find(word)+' ';
            word=strtok(NULL," ");
        }
        ans.pop_back();
        return ans;
    }
};
