#include <string>
#include <vector>

#include "trie.h"

using namespace std;

TrieNode::TrieNode(char _nodeChar) {
    nodeChar = _nodeChar;
    isEndOfWord = false;
    childCount = 0;
    for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < 26; ++i) {
        delete children[i];
        children[i] = nullptr;
    }
}

inline int TrieNode::charToIndex(char ch) { return ch - 'a'; }

bool TrieNode::hasChild(char childChar) {
    int childIndex = charToIndex(childChar);
    return children[childIndex] != nullptr;
}

void TrieNode::addChild(char childChar) {
    int childIndex = charToIndex(childChar);
    children[childIndex] = new TrieNode(childChar);
    childCount++;
}

bool TrieNode::deleteChild(char childChar) {
    if (!hasChild(childChar)) {
        return false;
    }

    int childIndex = charToIndex(childChar);
    delete children[childIndex];
    children[childIndex] = nullptr;
    childCount--;

    return true;
}

TrieNode *TrieNode::getChild(char childChar) {
    int childIndex = charToIndex(childChar);
    return children[childIndex];
}

void TrieNode::markAsEndOfWord(bool _isEndOfWord) { isEndOfWord = _isEndOfWord; }

bool TrieNode::isNodeEndOfWord() { return isEndOfWord; }

int TrieNode::getNumChildren() { return childCount; }

Trie::Trie() { root = new TrieNode('\0'); }

Trie::~Trie() {
    delete root;
    root = nullptr;
}

void Trie::insert(string word) {
    TrieNode *currentNode = root;
    for (char ch : word) {
        if (!currentNode->hasChild(ch)) {
            currentNode->addChild(ch);
        }

        currentNode = currentNode->getChild(ch);
    }

    currentNode->markAsEndOfWord(true);
}

bool Trie::search(string word) {
    TrieNode *currentNode = root;
    for (char ch : word) {
        if (!currentNode->hasChild(ch)) {
            return false;
        }

        currentNode = currentNode->getChild(ch);
    }

    if (currentNode == nullptr) {
        return false;
    }

    return currentNode->isNodeEndOfWord();
}

bool Trie::startsWith(string prefix) {
    TrieNode *currentNode = root;
    for (char ch : prefix) {
        if (!currentNode->hasChild(ch)) {
            return false;
        }

        currentNode = currentNode->getChild(ch);
    }

    return currentNode != nullptr;
}

bool Trie::deleteWord(string word) {
    vector<TrieNode *> pathNodes;

    TrieNode *currentNode = root;
    for (char ch : word) {
        pathNodes.push_back(currentNode);

        if (!currentNode->hasChild(ch)) {
            return false;
        }

        currentNode = currentNode->getChild(ch);
    }

    // Note that the final currentNode is never pushed to pathNodes
    if (currentNode == nullptr || !currentNode->isNodeEndOfWord()) {
        return false;
    }

    currentNode->markAsEndOfWord(false);

    if (currentNode->getNumChildren() > 0) {
        return true;
    }

    // pathNodes has the same length as word and pathNodes[i] contains the parent of the char in
    // word[i] Traverse the reverse path
    int numNodesInPath = pathNodes.size();
    for (int i = numNodesInPath - 1; i >= 0; i--) {
        TrieNode *charParentNode = pathNodes[i];
        char wordChar = word[i];

        charParentNode->deleteChild(wordChar);

        if (charParentNode->getNumChildren() > 0) {
            break;
        }
    }

    return true;
}
