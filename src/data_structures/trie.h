#include <string>

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

    void insert(std::string word);
    bool search(std::string word);
    bool startsWith(std::string prefix);
    bool deleteWord(std::string word);
};
