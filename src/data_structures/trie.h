#include <string>

using namespace std;

class TrieNode {
  private:
    char nodeChar;
    TrieNode *children[26];
    bool isEndOfWord;
    int childCount;

  public:
    TrieNode(char _nodeChar);
    ~TrieNode();

    inline int charToIndex(char ch);
    bool hasChild(char childChar);
    void addChild(char childChar);
    bool deleteChild(char childChar);
    TrieNode *getChild(char childChar);
    void markAsEndOfWord(bool _isEndOfWord);
    bool isNodeEndOfWord();
    int getNumChildren();
};

class Trie {
  private:
    TrieNode *root;

  public:
    Trie();
    ~Trie();

    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
    bool deleteWord(string word);
};
