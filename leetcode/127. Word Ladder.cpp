// Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time.
// Each transformed word must exist in the word list.
// Return 0 if there is no such transformation sequence.

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 

// Constraints:

// 1 <= beginWord.length <= 100
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the strings in wordList are unique.

class Solution {
public:
    int ladderLength(string& beginWord, string& endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
            return 0;
        int n=beginWord.length(),nw=0;
        unordered_map<string,vector<int>> mp;
        for(auto& s:wordList){
            for(int i=0;i<n;++i){
                char ch='*';
                swap(ch,s[i]);
                mp[s].push_back(nw);
                swap(ch,s[i]);
            }
            nw++;
        }
        int ans=1;
        unordered_set<string_view> q[3];int front=0,back=1,temp=2;
        q[front].insert(beginWord);
        q[back].insert(endWord);
        bool visited[nw];
        fill(visited,visited+nw,false);
        while(!q[front].empty()){
            if(q[front].size()>q[back].size())
                swap(front,back);
            for(auto ss:q[front]){
                string s=ss.data();
                for(int i=0;i<n;++i){
                    char ch='*';
                    swap(ch,s[i]);
                    for(auto nei:mp[s]){
                        if(q[back].count(wordList[nei]))
                            return ans+1;
                        if(!visited[nei]){
                            visited[nei]=true;
                            q[temp].insert(wordList[nei]);
                        }
                    }
                    swap(ch,s[i]);
                }
            }
            q[front].clear();
            swap(front,temp);
            ans++;
        }
        return 0;
    }
};
